/*
** EPITECH PROJECT, 2020
** temp
** File description:
** RayMesh.cpp
*/

#include "RayMesh.hpp"

namespace Raylib {
    RayMesh::RayMesh()
    {
    }

    Mesh RayMesh::getMesh()
    {
        return _mesh;
    }

    void RayMesh::genMeshPoly(int sides, float radius)
    {
        _mesh = GenMeshPoly(sides, radius);
    }

    void RayMesh::genMeshPlane(float width, float length, int resX, int resZ)
    {
        _mesh = GenMeshPlane(width, length, resX, resZ);
    }

    void RayMesh::genMeshCube(float width, float height, float length)
    {
        _mesh = GenMeshCube(width, height, length);
    }

    void RayMesh::genMeshSphere(float radius, int rings, int slices)
    {
        _mesh = GenMeshSphere(radius, rings, slices);
    }

    void RayMesh::genMeshHemiSphere(float radius, int rings, int slices)
    {
        _mesh = GenMeshHemiSphere(radius, rings, slices);
    }

    void RayMesh::genMeshCylinder(float radius, float height, int slices)
    {
        _mesh = GenMeshCylinder(radius, height, slices);
    }

    void RayMesh::genMeshTorus(float radius, float size, int radSeg, int sides)
    {
        _mesh = GenMeshTorus(radius, size, radSeg, sides);
    }

    void RayMesh::genMeshKnot(float radius, float size, int radSeg, int sides)
    {
        _mesh = GenMeshKnot(radius, size, radSeg, sides);
    }

    void RayMesh::genMeshHeightmap(Image heightmap, Vector3 size)
    {
        _mesh = GenMeshHeightmap(heightmap, size);
    }

    void RayMesh::genMeshCubicmap(Image cubicmap, Vector3 cubeSize)
    {
        _mesh = GenMeshCubicmap(cubicmap, cubeSize);
    }

    void RayMesh::meshTangents(void)
    {
        MeshTangents(&_mesh);
    }

    void RayMesh::meshBinormals(void)
    {
        MeshBinormals(&_mesh);
    }
    
    RayMesh::~RayMesh()
    {
    }
}