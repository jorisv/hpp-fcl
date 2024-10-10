/*
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2019, CNRS-LAAS
 *  All rights reserved.
 */

/** \author Lucile Remigy, Joseph Mirabel */

#include <hpp/fcl/collision_func_matrix.h>
#include <hpp/fcl/narrowphase/narrowphase.h>
#include <../src/collision_node.h>
#include <hpp/fcl/internal/traversal_node_setup.h>
#include <hpp/fcl/internal/shape_shape_func.h>

namespace hpp {
namespace fcl {

// TraversalTraitsCollision for collision_func_matrix.cpp

template <typename TypeA, typename TypeB>
struct HPP_FCL_LOCAL TraversalTraitsCollision{};

#ifdef HPP_FCL_HAS_OCTOMAP

template <typename T_SH>
struct HPP_FCL_LOCAL TraversalTraitsCollision<T_SH, OcTree> {
  typedef ShapeOcTreeCollisionTraversalNode<T_SH> CollisionTraversal_t;
};

template <typename T_SH>
struct HPP_FCL_LOCAL TraversalTraitsCollision<OcTree, T_SH> {
  typedef OcTreeShapeCollisionTraversalNode<T_SH> CollisionTraversal_t;
};

template <>
struct HPP_FCL_LOCAL TraversalTraitsCollision<OcTree, OcTree> {
  typedef OcTreeCollisionTraversalNode CollisionTraversal_t;
};

template <typename T_BVH>
struct HPP_FCL_LOCAL TraversalTraitsCollision<OcTree, BVHModel<T_BVH> > {
  typedef OcTreeMeshCollisionTraversalNode<T_BVH> CollisionTraversal_t;
};

template <typename T_BVH>
struct HPP_FCL_LOCAL TraversalTraitsCollision<BVHModel<T_BVH>, OcTree> {
  typedef MeshOcTreeCollisionTraversalNode<T_BVH> CollisionTraversal_t;
};

template <typename T_HF>
struct HPP_FCL_LOCAL TraversalTraitsCollision<OcTree, HeightField<T_HF> > {
  typedef OcTreeHeightFieldCollisionTraversalNode<T_HF> CollisionTraversal_t;
};

template <typename T_HF>
struct HPP_FCL_LOCAL TraversalTraitsCollision<HeightField<T_HF>, OcTree> {
  typedef HeightFieldOcTreeCollisionTraversalNode<T_HF> CollisionTraversal_t;
};

#endif

// TraversalTraitsDistance for distance_func_matrix.cpp

template <typename TypeA, typename TypeB>
struct HPP_FCL_LOCAL TraversalTraitsDistance{};

#ifdef HPP_FCL_HAS_OCTOMAP

template <typename T_SH>
struct HPP_FCL_LOCAL TraversalTraitsDistance<T_SH, OcTree> {
  typedef ShapeOcTreeDistanceTraversalNode<T_SH> CollisionTraversal_t;
};

template <typename T_SH>
struct HPP_FCL_LOCAL TraversalTraitsDistance<OcTree, T_SH> {
  typedef OcTreeShapeDistanceTraversalNode<T_SH> CollisionTraversal_t;
};

template <>
struct HPP_FCL_LOCAL TraversalTraitsDistance<OcTree, OcTree> {
  typedef OcTreeDistanceTraversalNode CollisionTraversal_t;
};

template <typename T_BVH>
struct HPP_FCL_LOCAL TraversalTraitsDistance<OcTree, BVHModel<T_BVH> > {
  typedef OcTreeMeshDistanceTraversalNode<T_BVH> CollisionTraversal_t;
};

template <typename T_BVH>
struct HPP_FCL_LOCAL TraversalTraitsDistance<BVHModel<T_BVH>, OcTree> {
  typedef MeshOcTreeDistanceTraversalNode<T_BVH> CollisionTraversal_t;
};

#endif

}  // namespace fcl

}  // namespace hpp
