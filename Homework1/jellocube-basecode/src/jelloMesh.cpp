#include "JelloMesh.h"
#include <GL/glut.h>
#include <algorithm>

<<<<<<< HEAD
// TODO 
double JelloMesh::g_structuralKs = 5000.0;
double JelloMesh::g_structuralKd = 10.0;
double JelloMesh::g_attachmentKs = 5000.0;
double JelloMesh::g_attachmentKd = 10.0;
double JelloMesh::g_shearKs = 5000.0;
double JelloMesh::g_shearKd = 10.0;
double JelloMesh::g_bendKs = 8000.0;
double JelloMesh::g_bendKd = 10.0;
double JelloMesh::g_penaltyKs = 5000.0;
double JelloMesh::g_penaltyKd = 2.0;

//double JelloMesh::g_structuralKs = 500.0;
//double JelloMesh::g_structuralKd = 2.0;
//double JelloMesh::g_attachmentKs = 0.0;
//double JelloMesh::g_attachmentKd = 0.0;
//double JelloMesh::g_shearKs = 500.0;
//double JelloMesh::g_shearKd = 2.0;
//double JelloMesh::g_bendKs = 500.0;
//double JelloMesh::g_bendKd = 2.0;
//double JelloMesh::g_penaltyKs = 0.0;
//double JelloMesh::g_penaltyKd = 0.0;



JelloMesh::JelloMesh()
	: m_integrationType(JelloMesh::RK4)
	, m_drawflags(MESH | STRUCTURAL)
	, m_cols(0)
	, m_rows(0)
	, m_stacks(0)
	, m_width(0.0)
	, m_height(0.0)
	, m_depth(0.0)
{
	SetSize(1.0, 1.0, 1.0);
	SetGridSize(6, 6, 6);
=======
// TODO

double JelloMesh::g_penaltyKs = 0.0;
double JelloMesh::g_penaltyKd = 0.0;

JelloMesh::JelloMesh() :     
    m_integrationType(JelloMesh::RK4), 
    m_cols(0), m_rows(0), m_stacks(0), m_width(0.0), m_height(0.0), m_depth(0.0)
{
    SetSize(1.0, 1.0, 1.0);

>>>>>>> cb3c7e0f67557661bfe81c7f2daab929467cdb71
}

JelloMesh::~JelloMesh()
{
}

void JelloMesh::Reset()
{
	InitJelloMesh();
}

JelloMesh::Particle& JelloMesh::GetParticle(JelloMesh::ParticleGrid& grid, int i, int j, int k)
{
	return grid[i][j][k];
}

JelloMesh::Particle& JelloMesh::GetParticle(JelloMesh::ParticleGrid& grid, int idx)
{
	int i, j, k;
	GetCell(idx, i, j, k);
	return GetParticle(grid, i, j, k);
}

const JelloMesh::Particle& JelloMesh::GetParticle(const JelloMesh::ParticleGrid& grid, int i, int j, int k) const
{
	return grid[i][j][k];
}

const JelloMesh::Particle& JelloMesh::GetParticle(const JelloMesh::ParticleGrid& grid, int idx) const
{
	int i, j, k;
	GetCell(idx, i, j, k);
	return GetParticle(grid, i, j, k);
}

<<<<<<< HEAD
bool JelloMesh::isInterior(const JelloMesh::Spring& s) const
{
	int i1, j1, k1, i2, j2, k2;
	GetCell(s.m_p1, i1, j1, k1);
	GetCell(s.m_p2, i2, j2, k2);
	return isInterior(i1, j1, k1) || isInterior(i2, j2, k2);
}

bool JelloMesh::isInterior(int idx) const
{
	int i, j, k;
	GetCell(idx, i, j, k);
	return isInterior(i, j, k);
}

bool JelloMesh::isInterior(int i, int j, int k) const
{
	return (i * j * k * (m_rows - i) * (m_cols - j) * (m_stacks - k) != 0);
}

void JelloMesh::SetGridSize(int cols, int rows, int stacks)
{
	m_cols = cols;
	m_rows = rows;
	m_stacks = stacks;

	if (m_cols > 0 && m_rows > 0 && m_stacks > 0) {
		m_vparticles.resize(m_rows + 1);
		for (int i = 0; i < m_rows + 1; i++) {
			m_vparticles[i].resize(m_cols + 1);
			for (int j = 0; j < m_cols + 1; j++) {
				m_vparticles[i][j].resize(m_stacks + 1);
			}
		}
	}
	InitJelloMesh();
}

int JelloMesh::GetGridCols() const
{
	return m_cols;
}

int JelloMesh::GetGridRows() const
{
	return m_rows;
}

int JelloMesh::GetGridStacks() const
{
	return m_stacks;
}
=======


>>>>>>> cb3c7e0f67557661bfe81c7f2daab929467cdb71

void JelloMesh::SetSize(float width, float height, float depth)
{
	m_width = width;
	m_height = height;
	m_depth = depth;
	InitJelloMesh();
}

<<<<<<< HEAD
float JelloMesh::GetWidth() const
{
	return m_width;
}

float JelloMesh::GetHeight() const
{
	return m_height;
}

float JelloMesh::GetDepth() const
{
	return m_depth;
}
=======

>>>>>>> cb3c7e0f67557661bfe81c7f2daab929467cdb71

int JelloMesh::GetIndex(int i, int j, int k) const
{
	int cols = j;
	int rows = i * (m_rows + 1);
	int stacks = k * (m_cols + 1) * (m_stacks + 1);
	return cols + rows + stacks;
}

#define ROUND(x) (floor(x + 0.5))
#define FLOOR(x) (floor(x))
#define FRACT(x) (x - FLOOR(x))
void JelloMesh::GetCell(int idx, int& i, int& j, int& k) const
{
	float rows = m_rows + 1;
	float cols = m_cols + 1;
	float stacks = m_stacks + 1;

	// derived from idx = cols*(rows*k + i) + j
	float tmp = FLOOR(idx / cols);
	j = (int)ROUND(cols * (FRACT(idx / cols)));
	i = (int)ROUND(rows * (FRACT(tmp / rows)));
	k = (int)FLOOR(tmp / rows);
}

void JelloMesh::InitJelloMesh()
{
<<<<<<< HEAD
	m_vsprings.clear();

	if (m_width < 0.01 || m_height < 0.01 || m_depth < 0.01)
		return;
	if (m_cols < 1 || m_rows < 1 || m_stacks < 1)
		return;

	// Init particles
	float wcellsize = m_width / m_cols;
	float hcellsize = m_height / m_rows;
	float dcellsize = m_depth / m_stacks;

	for (int i = 0; i < m_rows + 1; i++) {
		for (int j = 0; j < m_cols + 1; j++) {
			for (int k = 0; k < m_stacks + 1; k++) {
				float x = -m_width * 0.5f + wcellsize * i;
				float y = 0.5 + hcellsize * j;
				float z = -m_depth * 0.5f + dcellsize * k;
				m_vparticles[i][j][k] = Particle(GetIndex(i, j, k), vec3(x, y, z));
			}
		}
	}

	// Setup structural springs
	ParticleGrid& g = m_vparticles;
	for (int i = 0; i < m_rows + 1; i++)
	{
		for (int j = 0; j < m_cols + 1; j++)
		{
			for (int k = 0; k < m_stacks + 1; k++)
			{
				if (j < m_cols) AddStructuralSpring(GetParticle(g, i, j, k), GetParticle(g, i, j + 1, k));
				if (i < m_rows) AddStructuralSpring(GetParticle(g, i, j, k), GetParticle(g, i + 1, j, k));
				if (k < m_stacks) AddStructuralSpring(GetParticle(g, i, j, k), GetParticle(g, i, j, k + 1));

				//if (j < m_cols - 1) AddBendSpring(GetParticle(g, i, j, k), GetParticle(g, i, j + 2, k));
				//if (i < m_rows - 1) AddBendSpring(GetParticle(g, i, j, k), GetParticle(g, i + 2, j, k));
				//if (k < m_stacks - 1) AddBendSpring(GetParticle(g, i, j, k), GetParticle(g, i, j, k + 2));
				if (j < m_cols - 2) AddBendSpring(GetParticle(g, i, j, k), GetParticle(g, i, j + 3, k));
				if (i < m_rows - 2) AddBendSpring(GetParticle(g, i, j, k), GetParticle(g, i + 3, j, k));
				if (k < m_stacks - 2) AddBendSpring(GetParticle(g, i, j, k), GetParticle(g, i, j, k + 3));

				//if (i < m_rows && j < m_cols) AddShearSpring(GetParticle(g, i, j, k), GetParticle(g, i + 1, j + 1, k));
				//if (i < m_rows && k < m_stacks) AddShearSpring(GetParticle(g, i, j, k), GetParticle(g, i + 1, j, k + 1));
				//if (j < m_cols && k < m_stacks) AddShearSpring(GetParticle(g, i, j, k), GetParticle(g, i, j + 1, k + 1));
				//if (i > 0 && j < m_cols) AddShearSpring(GetParticle(g, i, j, k), GetParticle(g, i - 1, j + 1, k));
				//if (i < m_rows && j > 0) AddShearSpring(GetParticle(g, i, j, k), GetParticle(g, i + 1, j - 1, k));
				//if (i > 0 && k < m_stacks) AddShearSpring(GetParticle(g, i, j, k), GetParticle(g, i - 1, j, k + 1));
				//if (j > 0 && k < m_stacks) AddShearSpring(GetParticle(g, i, j, k), GetParticle(g, i, j - 1, k + 1));

				if (j < m_cols && i < m_rows) AddShearSpring(GetParticle(g, i, j, k), GetParticle(g, i + 1, j + 1, k));
				if (j > 0 && i < m_rows) AddShearSpring(GetParticle(g, i, j, k), GetParticle(g, i + 1, j - 1, k));
				if (j < m_cols && i > 0) AddShearSpring(GetParticle(g, i, j, k), GetParticle(g, i - 1, j + 1, k));
				if (i < m_rows && k < m_stacks) AddShearSpring(GetParticle(g, i, j, k), GetParticle(g, i + 1, j, k + 1));
				if (k > 0 && i < m_rows)  AddShearSpring(GetParticle(g, i, j, k), GetParticle(g, i + 1, j, k - 1));
				if (j < m_cols && k < m_stacks) AddShearSpring(GetParticle(g, i, j, k), GetParticle(g, i, j + 1, k + 1));
				if (k > 0 && j < m_cols)  AddShearSpring(GetParticle(g, i, j, k), GetParticle(g, i, j + 1, k - 1));

				
				
			}
		}
	}


	// Init mesh geometry
	m_mesh.clear();
	m_mesh.push_back(FaceMesh(*this, XLEFT));
	m_mesh.push_back(FaceMesh(*this, XRIGHT));
	m_mesh.push_back(FaceMesh(*this, YTOP));
	m_mesh.push_back(FaceMesh(*this, YBOTTOM));
	m_mesh.push_back(FaceMesh(*this, ZFRONT));
	m_mesh.push_back(FaceMesh(*this, ZBACK));
}

void JelloMesh::AddStructuralSpring(Particle& p1, Particle& p2)
{
	double restLen = (p1.position - p2.position).Length();
	m_vsprings.push_back(Spring(STRUCTURAL, p1.index, p2.index, g_structuralKs, g_structuralKd, restLen));
}

void JelloMesh::AddBendSpring(JelloMesh::Particle& p1, JelloMesh::Particle& p2)
{
	double restLen = (p1.position - p2.position).Length();
	m_vsprings.push_back(Spring(BEND, p1.index, p2.index, g_bendKs, g_bendKd, restLen));
}

void JelloMesh::AddShearSpring(JelloMesh::Particle& p1, JelloMesh::Particle& p2)
{
	double restLen = (p1.position - p2.position).Length();
	m_vsprings.push_back(Spring(SHEAR, p1.index, p2.index, g_shearKs, g_shearKd, restLen));
}
=======

	float x, y, z;
	x = y = z = 0.0f;
	m_vparticles.resize(10);
    for (int i = 0; i <10; i++)
    {
		m_vparticles[i][j][k] = Particle(GetIndex(i, j, k), vec3(x, y, z));
    }

}

>>>>>>> cb3c7e0f67557661bfe81c7f2daab929467cdb71

void JelloMesh::SetIntegrationType(JelloMesh::IntegrationType type)
{
	m_integrationType = type;
}

JelloMesh::IntegrationType JelloMesh::GetIntegrationType() const
{
	return m_integrationType;
}

void JelloMesh::SetDrawFlags(unsigned int flags)
{
	m_drawflags = flags;
}

unsigned int JelloMesh::GetDrawFlags() const
{
	return m_drawflags;
}

<<<<<<< HEAD
void JelloMesh::DrawMesh(const vec3& eyePos)
{
	const ParticleGrid& g = m_vparticles;
	float red[4] = { 1.0, 0.4, 0.4, 0.8 };
	float white[4] = { 1.0, 1.0, 1.0, 1.0 };
	float pink[4] = { 0.5, 0.0, 0.0, 1.0 };
	float black[4] = { 0.0, 0.0, 0.0, 1.0 };
	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, pink);
	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, black);
	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, black);

	//glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, black);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, white);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, black);
	//glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, white);


	for (unsigned int i = 0; i < m_mesh.size(); i++) {
		m_mesh[i].CalcDistToEye(*this, eyePos);
	}
	std::sort(m_mesh.begin(), m_mesh.end(), FaceMesh::compare);
	for (unsigned int i = 0; i < m_mesh.size(); i++) {
		m_mesh[i].Draw(*this);
	}

	//glDisable(GL_LIGHTING);
	//for (unsigned int i = 0; i < m_mesh.size(); i++)
	//{
	//   m_mesh[i].DrawNormals(*this);
	//}
}

void JelloMesh::DrawSprings(double a)
{
	const ParticleGrid& g = m_vparticles;
	glBegin(GL_LINES);
	for (unsigned int i = 0; i < m_vsprings.size(); i++) {
		if (!(m_vsprings[i].m_type & m_drawflags))
			continue;
		if (isInterior(m_vsprings[i]))
			continue;

		switch (m_vsprings[i].m_type) {
		case BEND:
			glColor4f(1.0, 1.0, 0.0, a);
			break;
		case STRUCTURAL:
			glColor4f(1.0, 1.0, 0.0, a);
			break;
		case SHEAR:
			glColor4f(0.0, 1.0, 1.0, a);
			break;
		};

		vec3 p1 = GetParticle(g, m_vsprings[i].m_p1).position;
		vec3 p2 = GetParticle(g, m_vsprings[i].m_p2).position;
		glVertex3f(p1[0], p1[1], p1[2]);
		glVertex3f(p2[0], p2[1], p2[2]);
	}
	glEnd();
}

void JelloMesh::DrawCollisionNormals()
{
	const ParticleGrid& g = m_vparticles;
	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0);
	for (unsigned int i = 0; i < m_vcollisions.size(); i++) {
		Intersection intersection = m_vcollisions[i];
		if (isInterior(intersection.m_p))
			continue;

		const Particle& pt = GetParticle(g, intersection.m_p);
		vec3 normal = intersection.m_normal;
		vec3 end = pt.position + 0.2 * normal;
		glVertex3f(pt.position[0], pt.position[1], pt.position[2]);
		glVertex3f(end[0], end[1], end[2]);
	}
	glEnd();
=======

void JelloMesh::DrawCollisionNormals()
{
    const ParticleGrid& g = m_vparticles;
    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0);
    for(unsigned int i = 0; i < m_vcollisions.size(); i++)
    {
       Intersection intersection = m_vcollisions[i];
       //if (isInterior(intersection.m_p)) continue;

       const Particle& pt = GetParticle(g, intersection.m_p);
       vec3 normal = intersection.m_normal;
       vec3 end = pt.position + 0.2 * normal;
       glVertex3f(pt.position[0], pt.position[1], pt.position[2]);
       glVertex3f(end[0], end[1], end[2]);
    }     
    glEnd();
>>>>>>> cb3c7e0f67557661bfe81c7f2daab929467cdb71
}

void JelloMesh::DrawForces()
{
<<<<<<< HEAD
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	for (int i = 0; i < m_rows + 1; i++) {
		for (int j = 0; j < m_cols + 1; j++) {
			for (int k = 0; k < m_stacks + 1; k++) {
				Particle p = m_vparticles[i][j][k];
				if (isInterior(i, j, k))
					continue;

				vec3 normal = p.force.Normalize();
				vec3 end = p.position + 0.1 * normal;
				glVertex3f(p.position[0], p.position[1], p.position[2]);
				glVertex3f(end[0], end[1], end[2]);
			}
		}
	}
	glEnd();
=======
	glDisable(GL_LIGHTING);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    for (int i = 0; i < m_rows+1; i++)
    {
        for (int j = 0; j < m_cols+1; j++)
        {
            for (int k = 0; k < m_stacks+1; k++)
            {
                Particle p = m_vparticles[i][j][k];
               // if (isInterior(i,j,k)) continue;

                vec3 normal = p.force.Normalize();
                vec3 end = p.position + 0.1 * normal;
                glVertex3f(p.position[0], p.position[1], p.position[2]);
                glVertex3f(end[0], end[1], end[2]);
            }
        }
    }     
    glEnd();
	glEnable(GL_LIGHTING);
>>>>>>> cb3c7e0f67557661bfe81c7f2daab929467cdb71
}



void JelloMesh::DrawParticles()
{
<<<<<<< HEAD
	if (m_drawflags & MESH)
		DrawMesh(eyePos);

	if (m_drawflags & (STRUCTURAL | BEND | SHEAR)) {
		glDisable(GL_LIGHTING);
		glDisable(GL_DEPTH_TEST);
		glLineWidth(1.0);
		DrawSprings(0.2);
		glLineWidth(1.5);
		glEnable(GL_DEPTH_TEST);
		DrawSprings(0.4);
	}

	if (m_drawflags & NORMALS)
		DrawCollisionNormals();
	if (m_drawflags & FORCES)
		DrawForces();

	glEnable(GL_LIGHTING);
=======
	glDisable(GL_LIGHTING);
	glPointSize(18.0);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_NOTEQUAL, 0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glBegin(GL_POINTS);

	glColor4f(1.0, 1.0, 0.0, 0.99);
	for (int i = 0; i < m_rows + 1; i++)
	{
		for (int j = 0; j < m_cols + 1; j++)
		{
			for (int k = 0; k < m_stacks + 1; k++)
			{
				Particle& p = GetParticle(m_vparticles, i, j, k);
				glVertex3f(p.position[0], p.position[1], p.position[2]);

			}
		}
	}
	glEnd();
	glEnable(GL_LIGHTING);


	glDisable(GL_POINT_SMOOTH);
	glBlendFunc(GL_NONE, GL_NONE);
	glDisable(GL_BLEND);


	return;
}

void JelloMesh::Draw(const vec3& eyePos)
{
	DrawParticles();
	DrawForces();
>>>>>>> cb3c7e0f67557661bfe81c7f2daab929467cdb71
}

void JelloMesh::Update(double dt, const World& world, const vec3& externalForces) //floor collision
{
	m_externalForces = externalForces;

	CheckForCollisions(m_vparticles, world);
	ComputeForces(m_vparticles);
	ResolveContacts(m_vparticles);
	ResolveCollisions(m_vparticles);

	switch (m_integrationType) {
	case EULER:
		EulerIntegrate(dt);
		break;
	case MIDPOINT:
		MidPointIntegrate(dt);
		break;
	case RK4:
		RK4Integrate(dt);
		break;
	case VELOCITYVERLET:
		VelocityVerlet(dt);
		break;
	}
}

void JelloMesh::CheckForCollisions(ParticleGrid& grid, const World& world)
{
	m_vcontacts.clear();
	m_vcollisions.clear();
	//for all particles 
for (int i = 0; i < m_rows + 1; i++)
	{
		for (int j = 0; j < m_cols + 1; j++)
		{
			for (int k = 0; k < m_stacks + 1; k++)
			{
				Particle& p = GetParticle(m_vparticles, i, j, k);

				// 1. Check collisions with world objects
				for (unsigned int i = 0; i < world.m_shapes.size(); i++)
				{
					Intersection intersection;

					if (world.m_shapes[i]->GetType() == World::CYLINDER &&
						CylinderIntersection(p, (World::Cylinder*) world.m_shapes[i], intersection))
						{
							if (intersection.m_type == CONTACT) m_vcontacts.push_back(intersection);
							
							else m_vcollisions.push_back(intersection);
							}
						
					if (world.m_shapes[i]->GetType() == World::SPHERE && 
						SphereIntersection(p, (World::Sphere*) world.m_shapes[i], intersection))
					{
						if (intersection.m_type == CONTACT)
							m_vcontacts.push_back(intersection);

						else
							m_vcollisions.push_back(intersection);
					}
					else if (world.m_shapes[i]->GetType() == World::GROUND && FloorIntersection(p, intersection))
						{
						if (intersection.m_type == CONTACT) m_vcontacts.push_back(intersection);
						
						else  m_vcollisions.push_back(intersection);
						}
					}
				}
			}
		}
	}

void JelloMesh::ComputeForces(ParticleGrid& grid)
{
<<<<<<< HEAD
	// Add external forces to all points
	for (int i = 0; i < m_rows + 1; i++) {
		for (int j = 0; j < m_cols + 1; j++) {
			for (int k = 0; k < m_stacks + 1; k++) {
				Particle& p = GetParticle(m_vparticles, i, j, k);
				p.force = m_externalForces * p.mass; 
			}
		}
	}

	// Update springs
	for (unsigned int i = 0; i < m_vsprings.size(); i++) { //guidance from Sarah
		Spring& spring = m_vsprings[i];
		Particle& a = GetParticle(grid, spring.m_p1);
		Particle& b = GetParticle(grid, spring.m_p2);


		// TODO
		vec3 diff = a.position - b.position;
		double dist = diff.Length();
		if (dist != 0) {
		vec3 force = -(spring.m_Ks * (dist - spring.m_restLen) + spring.m_Kd * ((b.velocity - a.velocity) *diff / dist))* (diff / dist);
		a.force += force;
		b.force += -force;   //  Newtons 3rd law
		}
	}
=======
    // Add external froces to all points
    for (int i = 0; i < m_rows+1; i++)
    {
        for (int j = 0; j < m_cols+1; j++)
        {
            for (int k = 0; k < m_stacks+1; k++)
            {
                Particle& p = GetParticle(grid, i,j,k);
                p.force = m_externalForces * p.mass;
            }
        }
    }

    // Update Flocking
  // TODO


    
>>>>>>> cb3c7e0f67557661bfe81c7f2daab929467cdb71
}

void JelloMesh::ResolveContacts(ParticleGrid& grid)
{
	for (unsigned int i = 0; i < m_vcontacts.size(); i++)
	{
		const Intersection& contact = m_vcontacts[i];
		Particle& p = GetParticle(grid, contact.m_p);
		vec3 normal = contact.m_normal;

		double dist = contact.m_distance;
		vec3 diff = -dist * normal;
		double ps = g_penaltyKs;
		double pd = g_penaltyKd;

		if (dist != 0) {
			p.position = p.position + (dist * normal);
			p.velocity = (vec3(0.0, 1.0, 0.0)*pd);
			vec3 normalized_pos = contact.m_normal * contact.m_distance / abs(contact.m_distance);
			p.force = (g_penaltyKs * dist + (g_penaltyKd * Dot(p.velocity, contact.m_normal) / dist)) * (normalized_pos);
		}
	}
}

void JelloMesh::ResolveCollisions(ParticleGrid& grid)
{
	for (unsigned int i = 0; i < m_vcollisions.size(); i++) 
	{
		Intersection result = m_vcollisions[i];
		Particle& pt = GetParticle(grid, result.m_p);
		vec3 normal = result.m_normal;
		float dist = result.m_distance;
		double r = 0.8;
		
			pt.position = pt.position - (dist * normal);

			if (pt.velocity * normal < 0) {
				pt.velocity = pt.velocity - (2.0 * (pt.velocity * normal)) * (normal*r);
				//equation - v' = v - 2 (v*N) N r
			}
	}
}

bool JelloMesh::FloorIntersection(Particle& p, Intersection& intersection)
<<<<<<< HEAD
 {
	// TODO
	
	float epsilon_delta = 0.05;
	if (p.position[1] < 0.0)
		{
			intersection.m_p = p.index;
			intersection.m_distance = -p.position[1];
			intersection.m_normal = vec3(0.0, 1.0, 0.0);
			intersection.m_type = IntersectionType::CONTACT;
			cout << "Contact" << endl;
			return true;
		}
	else if (p.position[1] < 0.0 + epsilon_delta)
		{
			intersection.m_p = p.index;
			intersection.m_distance = epsilon_delta - p.position[1];
			intersection.m_normal = vec3(0.0, 1.0, 0.0);
			intersection.m_type = IntersectionType::COLLISION;
			cout << "Collisions" << endl;
			return true;
		}
		else 
		{
			return false;
		}
		
	}

bool JelloMesh::CylinderIntersection(Particle& p, World::Cylinder* cylinder,
	JelloMesh::Intersection& result)
{
	vec3 cylinderStart = cylinder->start;
	vec3 cylinderEnd = cylinder->end;
	vec3 cylinderAxis = cylinderEnd - cylinderStart;
	double cylinderRadius = cylinder->r;
	 
	// TODO --- use of Julie's link
	vec3 diff = cylinderStart - p.position;
	vec3 normal = normal.Normalize();
	double dist = normal.Length();
	double time = -(diff* cylinderAxis) / (cylinderAxis.Length() *cylinderAxis.Length());
	//cylinderstart = x1, cylinder axis = x2
	vec3 point = cylinderStart + time * cylinderAxis;
	//float normal = p.position - point;

	if (dist < cylinderRadius) //should be similar to floor intersection
	{ 
		result.m_p = p.index;
		result.m_distance = cylinderRadius - dist;
		result.m_type = IntersectionType::CONTACT;
		result.m_normal = normal.Normalize();

		return true;
	}
	else if (dist < cylinderRadius)
	{
		result.m_p = p.index;
		result.m_distance = dist - cylinderRadius;
		result.m_type = IntersectionType::COLLISION;
		result.m_normal = normal.Normalize();

		return true;
	}
	else
	{
	return false;
	}
}

bool JelloMesh::SphereIntersection(Particle& p, World::Sphere* sphere, JelloMesh::Intersection & result)
{
		vec3 center = sphere->pos;
		vec3 normal = (p.position - center);
		double radius = sphere->r;
		double dist = normal.Length();
		float epsilon_delta = 0.05;

		if (normal.Length() < radius)
		{
			result.m_p = p.index;
			result.m_distance = radius;
			result.m_type = IntersectionType::CONTACT;
			result.m_normal = normal;
			return true;
		}

		if (normal.Length() < radius + epsilon_delta)
		{
			result.m_p = p.index;
			result.m_distance = radius;
			result.m_type = IntersectionType::COLLISION;
			result.m_normal = normal.Normalize();
			return true;
		}
		return false;
}
=======
{
    // TODO
    return false;
}

bool JelloMesh::CylinderIntersection(Particle& p, World::Cylinder* cylinder, 
                                 JelloMesh::Intersection& result)
{
    vec3 cylinderStart = cylinder->start;
    vec3 cylinderEnd = cylinder->end;
    vec3 cylinderAxis = cylinderEnd - cylinderStart;
    double cylinderRadius = cylinder->r; 

    // TODO
    return false;
}

void JelloMesh::EulerIntegrate(double dt)
{
    // TODO
}

void JelloMesh::MidPointIntegrate(double dt)
{
    // TODO
}

void JelloMesh::RK4Integrate(double dt)
{
    double halfdt = 0.5 * dt;
    ParticleGrid target = m_vparticles;  // target is a copy!
    ParticleGrid& source = m_vparticles;  // source is a ptr!

    // Step 1
    ParticleGrid accum1 = m_vparticles;
    for (int i = 0; i < m_rows+1; i++)
    {
        for (int j = 0; j < m_cols+1; j++)
        {
            for (int k = 0; k < m_stacks+1; k++)
            {
                Particle& s = GetParticle(source, i,j,k);

                Particle& k1 = GetParticle(accum1, i,j,k);
                k1.force = halfdt * s.force * 1/s.mass;
                k1.velocity = halfdt * s.velocity;

                Particle& t = GetParticle(target, i,j,k);
                t.velocity = s.velocity + k1.force;
                t.position = s.position + k1.velocity;
            }
        }
    }

    ComputeForces(target);

    // Step 2
    ParticleGrid accum2 = m_vparticles;
    for (int i = 0; i < m_rows+1; i++)
    {
        for (int j = 0; j < m_cols+1; j++)
        {
            for (int k = 0; k < m_stacks+1; k++)
            {
                Particle& t = GetParticle(target, i,j,k);
                Particle& k2 = GetParticle(accum2, i,j,k);

                k2.force = halfdt * t.force * 1/t.mass;
                k2.velocity = halfdt * t.velocity;

                Particle& s = GetParticle(source, i,j,k);
                t.velocity = s.velocity + k2.force;
                t.position = s.position + k2.velocity;
            }
        }
    }

    ComputeForces(target);

    // Step 3
    ParticleGrid accum3 = m_vparticles;
    for (int i = 0; i < m_rows+1; i++)
    {
        for (int j = 0; j < m_cols+1; j++)
        {
            for (int k = 0; k < m_stacks+1; k++)
            {
            Particle& t = GetParticle(target, i,j,k);
            Particle& k3 = GetParticle(accum3, i,j,k);

            k3.force = dt * t.force * 1/t.mass;
            k3.velocity = dt * t.velocity;

            Particle& s = GetParticle(source, i,j,k);
            t.velocity = s.velocity + k3.force;
            t.position = s.position + k3.velocity;
            }
        }
    }
    ComputeForces(target);

    // Step 4
    ParticleGrid accum4 = m_vparticles;
    for (int i = 0; i < m_rows+1; i++)
    {
        for (int j = 0; j < m_cols+1; j++)
        {
            for (int k = 0; k < m_stacks+1; k++)
            {
                Particle& t = GetParticle(target, i,j,k);
                Particle& k4 = GetParticle(accum4, i,j,k);

                k4.force = dt * t.force * 1/t.mass;
                k4.velocity = dt * t.velocity;
            }
        }
    }

    // Put it all together
    double asixth = 1/6.0;
    double athird = 1/3.0;
    for (int i = 0; i < m_rows+1; i++)
    {
        for (int j = 0; j < m_cols+1; j++)
        {
            for (int k = 0; k < m_stacks+1; k++)
            {
                Particle& p = GetParticle(m_vparticles, i,j,k);
                Particle& k1 = GetParticle(accum1, i,j,k);
                Particle& k2 = GetParticle(accum2, i,j,k);
                Particle& k3 = GetParticle(accum3, i,j,k);
                Particle& k4 = GetParticle(accum4, i,j,k);
                
                p.velocity = p.velocity + asixth * k1.force + 
                    athird * k2.force + athird * k3.force + asixth * k4.force;

                p.position = p.position + asixth * k1.velocity + 
                    athird * k2.velocity + athird * k3.velocity + asixth * k4.velocity;
            }
        }
    }
}




>>>>>>> cb3c7e0f67557661bfe81c7f2daab929467cdb71


	void JelloMesh::EulerIntegrate(double dt)
	{
		ParticleGrid& source = m_vparticles;  // source is a ptr!

											  // Step 1
		for (int i = 0; i < m_rows + 1; i++)
		{
			for (int j = 0; j < m_cols + 1; j++)
			{
				for (int k = 0; k < m_stacks + 1; k++)
				{
					Particle& p = GetParticle(m_vparticles, i, j, k);
					p.velocity = p.velocity + dt * p.force * (1 / p.mass);
					p.position = p.position + dt * p.velocity;
				}
			}
		}
	}

	void JelloMesh::MidPointIntegrate(double dt)
	{

		double halfdt = 0.5 * dt;//step 1
		ParticleGrid& target = m_vparticles;  // target is a copy!
		ParticleGrid& source = m_vparticles;  // source is a ptr!

											  // Step 1
		ParticleGrid accum1 = m_vparticles;
		for (int i = 0; i < m_rows + 1; i++)
		{
			for (int j = 0; j < m_cols + 1; j++)
			{
				for (int k = 0; k < m_stacks + 1; k++)
				{
					Particle& s = GetParticle(source, i, j, k);

					Particle& k1 = GetParticle(accum1, i, j, k);
					k1.force = halfdt * s.force * 1 / s.mass;
					k1.velocity = halfdt * s.velocity;

					Particle& t = GetParticle(target, i, j, k);
					t.velocity = s.velocity + k1.force;
					t.position = s.position + k1.velocity;

				}
			}
		}

		ComputeForces(target);

		// Step 2
		ParticleGrid accum2 = m_vparticles;
		for (int i = 0; i < m_rows + 1; i++)
		{
			for (int j = 0; j < m_cols + 1; j++)
			{
				for (int k = 0; k < m_stacks + 1; k++)
				{
					Particle& t = GetParticle(target, i, j, k);
					Particle& k2 = GetParticle(accum2, i, j, k);

					k2.force = halfdt * t.force * 1 / t.mass;
					k2.velocity = halfdt * t.velocity;

					Particle& s = GetParticle(source, i, j, k);
					t.velocity = s.velocity + k2.force;
					t.position = s.position + k2.velocity;
				}
			}
		}
	
		for (int i = 0; i < m_rows + 1; i++)
		{
			for (int j = 0; j < m_cols + 1; j++)
			{
				for (int k = 0; k < m_stacks + 1; k++)
				{
					Particle& p = GetParticle(source, i, j, k);
					Particle& k1 = GetParticle(accum1, i, j, k);
					Particle& k2 = GetParticle(accum2, i, j, k);
					//application of midpoint formula
					p.velocity = p.velocity + dt * ((0.5 * p.force + 0.5 * k1.force) * 1 / p.mass);
					p.position = p.position + dt * (0.5 * p.velocity + 0.5 * k1.velocity);
				}
			}
		}
	}


	
	void JelloMesh::RK4Integrate(double dt)
	{
		double halfdt = 0.5 * dt;
		ParticleGrid target = m_vparticles;  // target is a copy!
		ParticleGrid& source = m_vparticles;  // source is a ptr!

											  // Step 1
		ParticleGrid accum1 = m_vparticles;
		for (int i = 0; i < m_rows + 1; i++)
		{
			for (int j = 0; j < m_cols + 1; j++)
			{
				for (int k = 0; k < m_stacks + 1; k++)
				{
					Particle& s = GetParticle(source, i, j, k);

					Particle& k1 = GetParticle(accum1, i, j, k);
					k1.force = halfdt * s.force * 1 / s.mass;
					k1.velocity = halfdt * s.velocity;

					Particle& t = GetParticle(target, i, j, k);
					t.velocity = s.velocity + k1.force;
					t.position = s.position + k1.velocity;
				}
			}
		}

		ComputeForces(target);

		// Step 2
		ParticleGrid accum2 = m_vparticles;
		for (int i = 0; i < m_rows + 1; i++)
		{
			for (int j = 0; j < m_cols + 1; j++)
			{
				for (int k = 0; k < m_stacks + 1; k++)
				{
					Particle& t = GetParticle(target, i, j, k);
					Particle& k2 = GetParticle(accum2, i, j, k);

					k2.force = halfdt * t.force * 1 / t.mass;
					k2.velocity = halfdt * t.velocity;

					Particle& s = GetParticle(source, i, j, k);
					t.velocity = s.velocity + k2.force;
					t.position = s.position + k2.velocity;
				}
			}
		}

		ComputeForces(target);

		// Step 3
		ParticleGrid accum3 = m_vparticles;
		for (int i = 0; i < m_rows + 1; i++)
		{
			for (int j = 0; j < m_cols + 1; j++)
			{
				for (int k = 0; k < m_stacks + 1; k++)
				{
					Particle& t = GetParticle(target, i, j, k);
					Particle& k3 = GetParticle(accum3, i, j, k);

					k3.force = dt * t.force * 1 / t.mass;
					k3.velocity = dt * t.velocity;

					Particle& s = GetParticle(source, i, j, k);
					t.velocity = s.velocity + k3.force;
					t.position = s.position + k3.velocity;
				}
			}
		}
		ComputeForces(target);

		// Step 4
		ParticleGrid accum4 = m_vparticles;
		for (int i = 0; i < m_rows + 1; i++)
		{
			for (int j = 0; j < m_cols + 1; j++)
			{
				for (int k = 0; k < m_stacks + 1; k++)
				{
					Particle& t = GetParticle(target, i, j, k);
					Particle& k4 = GetParticle(accum4, i, j, k);

					k4.force = dt * t.force * 1 / t.mass;
					k4.velocity = dt * t.velocity;
				}
			}
		}

		// Put it all together
		double asixth = 1 / 6.0;
		double athird = 1 / 3.0;
		for (int i = 0; i < m_rows + 1; i++)
		{
			for (int j = 0; j < m_cols + 1; j++)
			{
				for (int k = 0; k < m_stacks + 1; k++)
				{
					Particle& p = GetParticle(m_vparticles, i, j, k);
					Particle& k1 = GetParticle(accum1, i, j, k);
					Particle& k2 = GetParticle(accum2, i, j, k);
					Particle& k3 = GetParticle(accum3, i, j, k);
					Particle& k4 = GetParticle(accum4, i, j, k);

					p.velocity = p.velocity + asixth * k1.force +
						athird * k2.force + athird * k3.force + asixth * k4.force;

					p.position = p.position + asixth * k1.velocity +
						athird * k2.velocity + athird * k3.velocity + asixth * k4.velocity;
				}
			}
		}
	}

	void JelloMesh::VelocityVerlet(double dt)
	{// x(t+dt) = x(t) + v(t)dt + (1/2)A(t) dt^2 this works with velocity
		//v(t+dt) = v(t) + (1/2)(A (t) +A(t+dt)) dt
		double halfdt = 0.5 * dt;
		ParticleGrid target = m_vparticles;  // target is a copy!
		ParticleGrid& source = m_vparticles;  // source is a ptr!

				ParticleGrid accum1 = m_vparticles;
				for (int i = 0; i < m_rows + 1; i++)
				{
					for (int j = 0; j < m_cols + 1; j++)
					{
						for (int k = 0; k < m_stacks + 1; k++)
						{
							Particle& s = GetParticle(source, i, j, k);

							Particle& k1 = GetParticle(accum1, i, j, k);
							k1.force = halfdt * s.force * 1 / s.mass;
							k1.velocity = halfdt * s.velocity;

							Particle& t = GetParticle(target, i, j, k);
							t.velocity = s.velocity + k1.force;
							t.position = s.position + k1.velocity;
						}
					}
				}

				ComputeForces(target);

				// Step 2
				ParticleGrid accum2 = m_vparticles;
				for (int i = 0; i < m_rows + 1; i++)
				{
					for (int j = 0; j < m_cols + 1; j++)
					{
						for (int k = 0; k < m_stacks + 1; k++)
						{
							Particle& t = GetParticle(target, i, j, k);
							Particle& k2 = GetParticle(accum2, i, j, k);

							k2.force = halfdt * t.force * 1 / t.mass;
							k2.velocity = halfdt * t.velocity;

							Particle& s = GetParticle(source, i, j, k);
							t.velocity = s.velocity + k2.force;
							t.position = s.position + k2.velocity;
						}
					}
				}

				ComputeForces(target);

				// Step 3
				ParticleGrid accum3 = m_vparticles;
				for (int i = 0; i < m_rows + 1; i++)
				{
					for (int j = 0; j < m_cols + 1; j++)
					{
						for (int k = 0; k < m_stacks + 1; k++)
						{
							Particle& t = GetParticle(target, i, j, k);
							Particle& k3 = GetParticle(accum3, i, j, k);

							k3.force = dt * t.force * 1 / t.mass;
							k3.velocity = dt * t.velocity;

							Particle& s = GetParticle(source, i, j, k);
							t.velocity = s.velocity + k3.force;
							t.position = s.position + k3.velocity;
						}
					}
				}
				ComputeForces(target);

				// Step 4
				ParticleGrid accum4 = m_vparticles;
				for (int i = 0; i < m_rows + 1; i++)
				{
					for (int j = 0; j < m_cols + 1; j++)
					{
						for (int k = 0; k < m_stacks + 1; k++)
						{
							Particle& t = GetParticle(target, i, j, k);
							Particle& k4 = GetParticle(accum4, i, j, k);

							k4.force = dt * t.force * 1 / t.mass;
							k4.velocity = dt * t.velocity;
						}
					}
				}
				for (int i = 0; i < m_rows + 1; i++)
				{
					for (int j = 0; j < m_cols + 1; j++)
					{
						for (int k = 0; k < m_stacks + 1; k++)
						{
							Particle& t = GetParticle(target, i, j, k);
							Particle& p = GetParticle(m_vparticles, i, j, k);
							Particle& k1 = GetParticle(accum1, i, j, k);
							Particle& k2 = GetParticle(accum2, i, j, k);
							Particle& k3 = GetParticle(accum3, i, j, k);
							Particle& k4 = GetParticle(accum4, i, j, k);

							//x(t + dt) = x(t) + v(t)dt + (1 / 2)A(t) dt ^ 2 (position)
							//v(t+dt) = v(t) + (1/2)(A (t) +A(t+dt)) dt (velocity)

							t.position += (k1.velocity *dt + k2.velocity * dt + k3.velocity * dt + k4.velocity *dt) + (halfdt * t.force * dt * dt);
							t.velocity += halfdt * (t.force + (t.force * dt)) *dt;


						}
					}
				}
					
				for (int i = 0; i < m_rows + 1; i++)
				{
					for (int j = 0; j < m_cols + 1; j++)
					{
						for (int k = 0; k < m_stacks + 1; k++)
						{
							Particle& t = GetParticle(target, i, j, k);

							t.velocity += halfdt * (t.force + (t.force * dt)) *dt;

						}

					}
				}
				
	}




	//---------------------------------------------------------------------
	// Spring
	//---------------------------------------------------------------------
	JelloMesh::Spring::Spring() :
		m_type(JelloMesh::STRUCTURAL),
		m_p1(-1),
		m_p2(-1),
		m_Ks(1.0),
		m_Kd(1.0),
		m_restLen(1.0)
	{
	}

	JelloMesh::Spring::Spring(const JelloMesh::Spring& p)
		: m_type(p.m_type)
		, m_p1(p.m_p1)
		, m_p2(p.m_p2)
		, m_Ks(p.m_Ks)
		, m_Kd(p.m_Kd)
		, m_restLen(p.m_restLen)
	{
	}

	JelloMesh::Spring& JelloMesh::Spring::operator=(const JelloMesh::Spring& p)
	{
		if (&p == this)
			return *this;

		m_type = p.m_type;
		m_p1 = p.m_p1;
		m_p2 = p.m_p2;
		m_Ks = p.m_Ks;
		m_Kd = p.m_Kd;
		m_restLen = p.m_restLen;
		return *this;
	}

<<<<<<< HEAD
	JelloMesh::Spring::Spring(JelloMesh::SpringType t,
		int p1, int p2, double Ks, double Kd, double restLen)
		: m_type(t)
		, m_Ks(Ks)
		, m_Kd(Kd)
		, m_p1(p1)
		, m_p2(p2)
		, m_restLen(restLen)
	{
	}

	//---------------------------------------------------------------------
	// Particle
	//---------------------------------------------------------------------

	JelloMesh::Particle JelloMesh::Particle::EMPTY;

	JelloMesh::Particle::Particle(int idx, const vec3& p, const vec3& v, double m)
	{
		index = idx;
		position = p;
		velocity = v;
		force = vec3(0, 0, 0);
		mass = m;
	}

	JelloMesh::Particle::Particle()
		: index(-1)
		, position(0, 0, 0)
		, velocity(0, 0, 0)
		, force(0, 0, 0)
		, mass(1.0)
	{
	}

	JelloMesh::Particle::Particle(const JelloMesh::Particle& p)
		: index(p.index)
		, position(p.position)
		, velocity(p.velocity)
		, force(p.force)
		, mass(p.mass)
	{
	}

	JelloMesh::Particle& JelloMesh::Particle::operator=(const JelloMesh::Particle& p)
	{
		if (&p == this)
			return *this;

		index = p.index;
		position = p.position;
		velocity = p.velocity;
		force = p.force;
		mass = p.mass;
		return *this;
	}

	//---------------------------------------------------------------------
	// Intersection
	//---------------------------------------------------------------------

	JelloMesh::Intersection::Intersection()
		: m_p(-1)
		, m_normal(0, 0, 0)
		, m_distance(0)
		, m_type(CONTACT)
	{
	}

	JelloMesh::Intersection::Intersection(const JelloMesh::Intersection& p)

		: m_p(p.m_p)
		, m_normal(p.m_normal)
		, m_distance(p.m_distance)
		, m_type(p.m_type)
	{
	}

	JelloMesh::Intersection& JelloMesh::Intersection::operator=(const JelloMesh::Intersection& p)
	{
		if (&p == this)
			return *this;
		m_p = p.m_p;
		m_normal = p.m_normal;
		m_distance = p.m_distance;
		m_type = p.m_type;
		return *this;
	}

	JelloMesh::Intersection::Intersection(IntersectionType type, int p, const vec3& normal, double d)

		: m_p(p)
		, m_normal(normal)
		, m_distance(d)
		, m_type(type)
	{
	}

	//---------------------------------------------------------------------
	// Drawing
	//---------------------------------------------------------------------

	void JelloMesh::FaceMesh::Draw(const JelloMesh& m)
	{
		const ParticleGrid& g = m.m_vparticles;
		for (unsigned int strip = 0; strip < m_strips.size(); strip++) {
			const std::vector<int>& points = m_strips[strip];

			glBegin(GL_TRIANGLE_STRIP);
			for (unsigned int pi = 0; pi < points.size(); pi++) {
				int idx = points[pi];
				vec3 p = m.GetParticle(g, idx).position;

				vec3 n(0, 0, 0);
				const std::vector<int>& neighbors = m_neighbors[idx];
				if (neighbors.size() > 0) {
					vec3 pup = m.GetParticle(g, neighbors[0]).position;
					vec3 pdown = m.GetParticle(g, neighbors[1]).position;
					vec3 pleft = m.GetParticle(g, neighbors[2]).position;
					vec3 pright = m.GetParticle(g, neighbors[3]).position;

					vec3 n1 = -((pright - p) ^ (pup - p));
					vec3 n2 = -((pdown - p) ^ (pright - p));
					vec3 n3 = -((pleft - p) ^ (pdown - p));
					vec3 n4 = -((pup - p) ^ (pleft - p));

					n = n1 + n2 + n3 + n4;
					n = n.Normalize();
				}

				glNormal3f(n[0], n[1], n[2]);
				glVertex3f(p[0], p[1], p[2]);
			}
			glEnd();
		}
	}

	void JelloMesh::FaceMesh::DrawNormals(const JelloMesh& m)
	{
		glDisable(GL_LIGHTING);

		glBegin(GL_LINES);
		glColor3f(0.0, 1.0, 0.0);

		const ParticleGrid& g = m.m_vparticles;
		for (unsigned int strip = 0; strip < m_strips.size(); strip++) {
			const std::vector<int>& points = m_strips[strip];
			for (unsigned int pi = 0; pi < points.size(); pi++) {
				int idx = points[pi];
				vec3 p = m.GetParticle(g, idx).position;

				const std::vector<int>& neighbors = m_neighbors[idx];
				if (neighbors.size() == 0)
					continue;

				vec3 pup = m.GetParticle(g, neighbors[0]).position;
				vec3 pdown = m.GetParticle(g, neighbors[1]).position;
				vec3 pleft = m.GetParticle(g, neighbors[2]).position;
				vec3 pright = m.GetParticle(g, neighbors[3]).position;

				vec3 n1 = -((pright - p) ^ (pup - p));
				vec3 n2 = -((pdown - p) ^ (pright - p));
				vec3 n3 = -((pleft - p) ^ (pdown - p));
				vec3 n4 = -((pup - p) ^ (pleft - p));

				vec3 n = n1 + n2 + n3 + n4;
				n = n.Normalize();

				vec3 end = p + 0.2 * n;
				glVertex3f(p[0], p[1], p[2]);
				glVertex3f(end[0], end[1], end[2]);
			}
		}

		glEnd();
		glEnable(GL_LIGHTING);
	}

#define R(i) max(0, min(i, m.m_rows)) // CLAMP row index
#define C(j) max(0, min(j, m.m_cols)) // CLAMP col index
#define D(j) max(0, min(j, m.m_stacks)) // CLAMP stack index
	JelloMesh::FaceMesh::FaceMesh(const JelloMesh& m, JelloMesh::Face f)
	{
		const ParticleGrid& g = m.m_vparticles;
		switch (f) {
		case ZFRONT:
			m_strips.resize(m.m_rows);
			for (int i = 0; i < m.m_rows + 1; i++)
				for (int j = 0; j < m.m_cols + 1; j++) {
					if (i < m.m_rows) {
						m_strips[i].push_back(m.GetIndex(i + 1, j, 0));
						m_strips[i].push_back(m.GetIndex(i, j, 0));
					}

					std::vector<int> neighbors;
					neighbors.push_back(m.GetIndex(R(i), C(j + 1), D(0)));
					neighbors.push_back(m.GetIndex(R(i), C(j - 1), D(0)));
					neighbors.push_back(m.GetIndex(R(i - 1), C(j), D(0)));
					neighbors.push_back(m.GetIndex(R(i + 1), C(j), D(0)));
					m_neighbors[m.GetIndex(i, j, 0)] = neighbors;
				}
			break;
		case ZBACK:
			m_strips.resize(m.m_rows);
			for (int i = 0; i < m.m_rows + 1; i++)
				for (int j = 0; j < m.m_cols + 1; j++) {
					if (i < m.m_rows) {
						m_strips[i].push_back(m.GetIndex(i + 1, j, m.m_stacks));
						m_strips[i].push_back(m.GetIndex(i, j, m.m_stacks));
					}

					std::vector<int> neighbors;
					neighbors.push_back(m.GetIndex(R(i + 1), C(j), D(m.m_stacks)));
					neighbors.push_back(m.GetIndex(R(i - 1), C(j), D(m.m_stacks)));
					neighbors.push_back(m.GetIndex(R(i), C(j - 1), D(m.m_stacks)));
					neighbors.push_back(m.GetIndex(R(i), C(j + 1), D(m.m_stacks)));
					m_neighbors[m.GetIndex(i, j, m.m_stacks)] = neighbors;
				}
			break;
		case XLEFT:
			m_strips.resize(m.m_cols);
			for (int j = 0; j < m.m_cols + 1; j++)
				for (int k = 0; k < m.m_stacks + 1; k++) {
					if (j < m.m_cols) {
						m_strips[j].push_back(m.GetIndex(0, j + 1, k));
						m_strips[j].push_back(m.GetIndex(0, j, k));
					}

					std::vector<int> neighbors;
					neighbors.push_back(m.GetIndex(R(0), C(j), D(k + 1)));
					neighbors.push_back(m.GetIndex(R(0), C(j), D(k - 1)));
					neighbors.push_back(m.GetIndex(R(0), C(j - 1), D(k)));
					neighbors.push_back(m.GetIndex(R(0), C(j + 1), D(k)));
					m_neighbors[m.GetIndex(0, j, k)] = neighbors;
				}
			break;
		case XRIGHT:
			m_strips.resize(m.m_cols);
			for (int j = 0; j < m.m_cols + 1; j++)
				for (int k = 0; k < m.m_stacks + 1; k++) {
					if (j < m.m_cols) {
						m_strips[j].push_back(m.GetIndex(m.m_rows, j + 1, k));
						m_strips[j].push_back(m.GetIndex(m.m_rows, j, k));
					}

					std::vector<int> neighbors;
					neighbors.push_back(m.GetIndex(R(m.m_rows), C(j + 1), D(k)));
					neighbors.push_back(m.GetIndex(R(m.m_rows), C(j - 1), D(k)));
					neighbors.push_back(m.GetIndex(R(m.m_rows), C(j), D(k - 1)));
					neighbors.push_back(m.GetIndex(R(m.m_rows), C(j), D(k + 1)));
					m_neighbors[m.GetIndex(m.m_rows, j, k)] = neighbors;
				}
			break;
		case YBOTTOM:
			m_strips.resize(m.m_rows);
			for (int i = 0; i < m.m_rows + 1; i++)
				for (int k = 0; k < m.m_stacks + 1; k++) {
					if (i < m.m_rows) {
						m_strips[i].push_back(m.GetIndex(i + 1, 0, k));
						m_strips[i].push_back(m.GetIndex(i, 0, k));
					}

					std::vector<int> neighbors;
					neighbors.push_back(m.GetIndex(R(i + 1), C(0), D(k)));
					neighbors.push_back(m.GetIndex(R(i - 1), C(0), D(k)));
					neighbors.push_back(m.GetIndex(R(i), C(0), D(k - 1)));
					neighbors.push_back(m.GetIndex(R(i), C(0), D(k + 1)));
					m_neighbors[m.GetIndex(i, 0, k)] = neighbors;
				}
			break;
		case YTOP:
			m_strips.resize(m.m_rows);
			for (int i = 0; i < m.m_rows + 1; i++)
				for (int k = 0; k < m.m_stacks + 1; k++) {
					if (i < m.m_rows) {
						m_strips[i].push_back(m.GetIndex(i + 1, m.m_cols, k));
						m_strips[i].push_back(m.GetIndex(i, m.m_cols, k));
					}

					std::vector<int> neighbors;
					neighbors.push_back(m.GetIndex(R(i), C(m.m_cols), D(k + 1)));
					neighbors.push_back(m.GetIndex(R(i), C(m.m_cols), D(k - 1)));
					neighbors.push_back(m.GetIndex(R(i - 1), C(m.m_cols), D(k)));
					neighbors.push_back(m.GetIndex(R(i + 1), C(m.m_cols), D(k)));
					m_neighbors[m.GetIndex(i, m.m_cols, k)] = neighbors;
				}
			break;
		}
	}

	void JelloMesh::FaceMesh::CalcDistToEye(const JelloMesh& m, const vec3& eyePos)
	{
		std::vector<int> points = m_strips[(int)(m_strips.size() * 0.5)];
		int idx = points[(int)(points.size() * 0.5)];
		vec3 pos = m.GetParticle(m.m_vparticles, idx).position;
		distToEye = (pos - eyePos).Length();
	}

	bool JelloMesh::FaceMesh::compare(const FaceMesh& one, const FaceMesh& other)
	{
		return one.distToEye > other.distToEye;
	}
=======
//---------------------------------------------------------------------
// Drawing
//---------------------------------------------------------------------
>>>>>>> cb3c7e0f67557661bfe81c7f2daab929467cdb71
