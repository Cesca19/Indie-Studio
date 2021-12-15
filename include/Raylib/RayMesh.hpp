/*
** EPITECH PROJECT, 2020
** temp
** File description:
** RayMesh.hpp
*/

#ifndef RAYMESH_HPP
#define RAYMESH_HPP

#include "myRaylib.hpp"

namespace Raylib {
    class RayMesh {
        public:
            /**
             * @brief Construct a new Ray Mesh object
             * 
             */
            RayMesh();
            /**
             * @brief Generate polygonal mesh
             * 
             * @param sides 
             * @param radius 
             */
            void genMeshPoly(int sides, float radius);
            /**
             * @brief Generate plane mesh
             * 
             * @param width 
             * @param length 
             * @param resX 
             * @param resZ 
             */
            void genMeshPlane(float width, float length, int resX, int resZ);
            /**
             * @brief Generate cuboid mesh
             * 
             * @param width 
             * @param height 
             * @param length 
             */
            void genMeshCube(float width, float height, float length);
            /**
             * @brief Generate sphere mesh
             * 
             * @param radius 
             * @param rings 
             * @param slices 
             */
            void genMeshSphere(float radius, int rings, int slices);
            /**
             * @brief Generate half-sphere mesh
             * 
             * @param radius 
             * @param rings 
             * @param slices 
             */
            void genMeshHemiSphere(float radius, int rings, int slices);
            /**
             * @brief Generate cylinder mesh
             * 
             * @param radius 
             * @param height 
             * @param slices 
             */
            void genMeshCylinder(float radius, float height, int slices);
            /**
             * @brief Generate torus mesh
             * 
             * @param radius 
             * @param size 
             * @param radSeg 
             * @param sides 
             */
            void genMeshTorus(float radius, float size, int radSeg, int sides);
            /**
             * @brief Generate trefoil knot mesh
             * 
             * @param radius 
             * @param size 
             * @param radSeg 
             * @param sides 
             */
            void genMeshKnot(float radius, float size, int radSeg, int sides);
            /**
             * @brief Generate heightmap mesh from image data
             * 
             * @param heightmap 
             * @param size 
             */
            void genMeshHeightmap(Image heightmap, Vector3 size);
            /**
             * @brief Generate cubes-based map mesh from image data
             * 
             * @param cubicmap 
             * @param cubeSize 
             */
            void genMeshCubicmap(Image cubicmap, Vector3 cubeSize);
            /**
             * @brief Compute mesh tangents
             * 
             */
            void meshTangents(void);
            /**
             * @brief Compute mesh binormals
             *  
             */
            void meshBinormals(void);
            /**
             * @brief Get the Mesh object
             * 
             * @return Mesh 
             */
            Mesh getMesh(void);
            /**
             * @brief Destroy the Ray Mesh object
             * 
             */
            ~RayMesh();
        private:
            Mesh _mesh;

    };
};

#endif