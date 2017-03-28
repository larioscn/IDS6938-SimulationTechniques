/*
  A simple program that simulates 5 MM1 queues at an airport. The first queue
  feeds 3 other queues that work in parallel. These feed a final queue.
  Simulation runs until error below threshold and, at the end,
  a performance evaluation report is shown, and logs are generated
  for plotting and analysis.
*/

using namespace std;

#include <random>
#include "customer.h"
#include "mm1_queue.h"


std::random_device rd;

void pause()
{
 std::string sInputString;
 // Wait for input from stdin (the keyboard)
 cout << "Continue (y)?";
 std::cin >> sInputString;
}



int main(int argc, char* argv[])
{
   int next = 0;
//   test_random_number_generator();

   for (int cur_lambda = 3; cur_lambda < 34; cur_lambda++)
   {
      
	   //TODO Create MM1_Queue objects to capture the airport senario.
	   //************************************************************
	   // Starting Queue - ID and ticket check-in
	   MM1_Queue    IDCHECK;
	   IDCHECK.set_file_names("IDCHECK_log.txt", "IDCHECK_wait.txt", "IDCHECK_service.txt");
	   IDCHECK.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   IDCHECK.set_mu(53);
	   IDCHECK.autogenerate_new_arrivals(true);
	   IDCHECK.initialize();
	   IDCHECK.set_seed(1, rd());   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())
	   

	   // 2nd Queue - 1st station metal detector
	   MM1_Queue    MetalDetector_1;
	   MetalDetector_1.set_file_names("MetalDetector_1_log.txt", "MetalDetector_1_wait.txt", "MetalDetector_1_service.txt");
	   MetalDetector_1.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   MetalDetector_1.set_mu(20);
	   MetalDetector_1.autogenerate_new_arrivals(false);
	   MetalDetector_1.initialize();
	   MetalDetector_1.set_seed(1, (rd(), rd()));   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())
	   

	   //3rd Queue - 2nd station metal detector
	   MM1_Queue    MetalDetector_2;
	   MetalDetector_2.set_file_names("MetalDetector_2_log.txt", "MetalDetector_2_wait.txt", "MetalDetector_2_service.txt");
	   MetalDetector_2.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   MetalDetector_2.set_mu(20);
	   MetalDetector_1.autogenerate_new_arrivals(false);
	   MetalDetector_2.initialize();
	   MetalDetector_2.set_seed(1, (rd(), rd()));   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())

	   //4th Queue - 3rd station metal detector
	   MM1_Queue    MetalDetector_3;
	   MetalDetector_3.set_file_names("MetalDetector_3_log.txt", "MetalDetector_3_wait.txt", "MetalDetector_3_service.txt");
	   MetalDetector_3.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   MetalDetector_3.set_mu(20);
	   MetalDetector_3.initialize();
	   MetalDetector_1.autogenerate_new_arrivals(false);
	   MetalDetector_3.set_seed(1, (rd(), rd()));   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())

	   //5th Queue - Boarding
	   MM1_Queue    Boarding;
	   Boarding.set_file_names("Boarding_log.txt", "Boarding_wait.txt", "Boarding_service.txt");
	   Boarding.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   Boarding.set_mu(80);
	   Boarding.autogenerate_new_arrivals(false);
	   Boarding.initialize();
	   Boarding.set_seed(1, (rd(), rd()));   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())


	  std::cout << std::endl;

	   std::cout << "IDCheck is within CI:"<< IDCHECK.is_within_confidence_interval() << endl;
	   std::cout << "MetalDetector_1 is within CI:" << MetalDetector_1.is_within_confidence_interval() << endl;
	   std::cout << "MetalDetector_2 is within CI:" << MetalDetector_2.is_within_confidence_interval() << endl;
	   std::cout << "MetalDetector_3 is within CI:" << MetalDetector_3.is_within_confidence_interval() << endl;
	   std::cout << "Boarding is within CI:" << Boarding.is_within_confidence_interval() << endl;

	   std::cout << "IDCheck is in error range:" << !IDCHECK.is_within_error_range(0.002) << endl;
	   std::cout << "MetalDetector_1 is in error range:" << !MetalDetector_1.is_within_error_range(0.002) << endl;
	   std::cout << "MetalDetector_2 is in error range:" << !MetalDetector_2.is_within_error_range(0.002) << endl;
	   std::cout << "MetalDetector_3 is in error range:" << !MetalDetector_3.is_within_error_range(0.002) << endl;
	   std::cout << "Boarding is in error range:" << !Boarding.is_within_error_range(0.002) << endl;

	   std::cout << std::endl;
   for (; 
		//TODO: add is_within_error_range check
	   !IDCHECK.is_within_error_range(0.002) || 
	   !MetalDetector_1.is_within_error_range(0.002) || 
	   !MetalDetector_2.is_within_error_range(0.002) || 
	   !MetalDetector_3.is_within_error_range(0.002) || 
	   !Boarding.is_within_error_range(0.002)
       ;)
   {
	   Customer cust = IDCHECK.process_next_event();    // =  TODO: process next event;
	   Customer cust2 = IDCHECK.process_next_event();   // =  TODO: process next event;
	   Customer cust3 = IDCHECK.process_next_event();   // =  TODO: process next event;
	   Customer cust4 = IDCHECK.process_next_event();   // =  TODO: process next event;
	   //TODO: one more process_next_event for the last object.

       if (cust.get_type() == Customer::COMPLETED())
       {
          switch(next)
          {
            case 0:
				//TODO add_external_arrival() for your security gates;
				MetalDetector_1.add_external_arrival();
				
				break;
            case 1:
				//TODO add_external_arrival() for your security gates;
				MetalDetector_2.add_external_arrival();
				break;
            case 2:
                //TODO add_external_arrival() for your security gates;
				MetalDetector_3.add_external_arrival();
				break;
          }
          next++;
          if (next%3==0) next = 0;
       }
       if (cust2.get_type() == Customer::COMPLETED() || cust3.get_type() == Customer::COMPLETED() || cust4.get_type() == Customer::COMPLETED())
       {
		   //TODO add_external_arrival(); on your final boarding MM1_Queue object
		   Boarding.add_external_arrival();
	   }
   }

   //TODO Output statistics airport senario.
   IDCHECK.get_current_time();
   IDCHECK.output(); cout << "*****************" << endl;
   IDCHECK.plot_results_output();

   //MetalDetector_1.plot_results_output();
   //MetalDetector_2.plot_results_output();
   //MetalDetector_3.plot_results_output();
   //Boarding.plot_results_output();

   MetalDetector_1.output(); cout << "*****************" << endl;
   MetalDetector_2.output(); cout << "*****************" << endl;
   MetalDetector_3.output(); cout << "*****************" << endl;
   Boarding.output(); cout << "*****************" << endl;

   //**************************************************************************

   }

   return(0);
}

