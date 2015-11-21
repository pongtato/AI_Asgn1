#include "Model.h"

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#include <windows.h> // Header File For Windows
#include <gl\gl.h> // Header File For The OpenGL32 Library
#include <gl\glu.h> // Header File For The GLu32 Library
#include "GL\glew.h"
#include "shader.hpp"
#include <stdio.h>
#include "MeshBuilder.h"
#include "LoadTGA.h"

CModel::CModel(void)
	: m_cModelMesh(NULL)
{
	vTopLeft = Vector3( 1.0f, 1.0f, 1.0f );
	vBottomRight = Vector3( -1.0f, -1.0f, -1.0f );
	red = 128;
	green = 255;
	blue = 0;
}

CModel::~CModel(void)
{
	if (m_cModelMesh != NULL)
	{
		m_cModelMesh = NULL;
		delete m_cModelMesh;
	}
}

void CModel::Init(Mesh *mesh)
{
	m_cModelMesh = mesh;
}

Mesh* CModel::getMesh(void)
{
	return m_cModelMesh;
}

void CModel::Draw(bool m_bLight)
{
	if (m_cModelMesh)
	{
		m_cModelMesh->Render();
	}
}

void CModel::SetColor(const float red, const float green, const float blue)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
}

// Get the top left of the bounding box of the instance
Vector3 CModel::GetTopLeft(void)
{
	return Vector3(vTopLeft.x, vTopLeft.y, vTopLeft.z);
}

// Get the bottomright of the bounding box of the instance
Vector3 CModel::GetBottomRight(void)
{
	return Vector3(vBottomRight.x, vBottomRight.y, vBottomRight.z);
}