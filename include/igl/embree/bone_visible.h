#ifndef IGL_BONE_VISIBLE_H
#define IGL_BONE_VISIBLE_H
#include <Eigen/Core>
//
// BONE_VISIBLE  test whether vertices of mesh are "visible" to a given bone,
// where "visible" is defined as in [Baran & Popovic 07]. Instead of checking
// whether each point can see *any* of the bone, we just check if each point
// can see its own projection onto the bone segment. In other words, we project
// each vertex v onto the bone, projv. Then we check if there are any
// intersections between the line segment (projv-->v) and the mesh.
//
// [flag] = bone_visible(V,F,s,d);
//
// Input:
//    s  row vector of position of start end point of bone
//    d  row vector of position of dest end point of bone
//    V  #V by 3 list of vertex positions
//    F  #F by 3 list of triangle indices
// Output:
//    flag  #V by 1 list of bools (true) visible, (false) obstructed
//
// Note: This checks for hits along the segment which are facing in *any*
// direction from the ray.
//
template <
  typename DerivedV, 
  typename DerivedF, 
  typename DerivedSD,
  typename Derivedflag>
void bone_visible(
  const Eigen::PlainObjectBase<DerivedV> & V,
  const Eigen::PlainObjectBase<DerivedF> & F,
  const Eigen::PlainObjectBase<DerivedSD> & s,
  const Eigen::PlainObjectBase<DerivedSD> & d,
  Eigen::PlainObjectBase<Derivedflag>  & flag);
#ifdef IGL_HEADER_ONLY
#  include "bone_visible.cpp"
#endif
#endif