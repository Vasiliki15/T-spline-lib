/*!
  @file demo.cpp
  @brief A demo file.

  Demos for T-spline, etc.
*/

#include "square.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>
#include <utils.h>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

#ifdef use_namespace
using namespace TSPLINE;
#endif

extern std::vector<std::string>& operator<<(std::vector<std::string> &container, const std::string &value);



std::vector<Real> points_x, points_y;
int last_link,last_edge, last_vert, last_edge_cond,last_point, last_node;
std::vector<Real> u_knot={0,0,0,1,1,2,2,3,3,4,4,4};
Real** map;


Circle::Circle()
 {
	_factory = makePtr<TFactory>();
	_textractor = makePtr<TExtractor>();
	_tvertex=makePtr<TVertex>();
	createMesh();
	//findLocalVecs();
  //addNode();
  //findLocalVecs();

}

void Circle::createMesh()
{
	createTSpline();
	createTImage();
	createTConnect();
	createTPointset();
	createTVertices();
	createTEdges();
 	createTLinks();
	createTEdgeConditions();
	createTFaces();
	createTNodes();
	createTPoints();


	patchTSpline();
	patchTImage();
	patchTConnect();
	patchTPointset();
	patchTEdges();
	patchTLinks();
	patchTEdgeConditions();
	patchTFaces();
	patchTVertices();
	patchTNodes();
	patchTPoints();


	prepareTObjects();

}

void Circle::findLocalVecs(){
	extractUVKnotsFromTNodeV4();
}

void Circle::addNode(){
    map=computeTMatrix(0.75,9,u_knot);
    computeNewControlPoint();
    unsigned int index;
    createNewNode(0.75, 0, &index);
    patchTSpline();
    std::vector<std::string> faces;
    std::vector<std::string> links={"l24", "l25"};
    std::vector<std::string> edges={"e12"};
    std::vector<std::string> vertices={"v9"};
    _factory->patchTImage("image", faces, links, edges, vertices);
    std::vector<std::string> nodes={"n9"};
    _factory->patchTConnect("nodes", nodes);
    std::vector<std::string> points={"p9"};
    _factory->patchTPointset("points", points);
    insertNewNode(index);
    prepareTObjects();
}

void Circle::createTSpline()
{
	_factory->createTSpline("circle");
}

void Circle::createTImage()
{
	_factory->createTImage("image");
}

void Circle::createTConnect()
{
	_factory->createTConnect("nodes");
}

void Circle::createTPointset()
{
	_factory->createTPointset("points");
}

void Circle::createTVertices()
{
	_factory->createTVertex("v0", 0.0, 0.0); // v
	_factory->createTVertex("v1", 0.5, 0.0); // v
	_factory->createTVertex("v2", 1, 0.0) ; // v
	_factory->createTVertex("v3", 0, 0.5); // v
	_factory->createTVertex("v4", 0.5, 0.5); // v
	_factory->createTVertex("v5", 1, 0.5); // v
	_factory->createTVertex("v6", 0, 1); // v
	_factory->createTVertex("v7", 0.5, 1); // v
	_factory->createTVertex("v8", 1, 1); // v
	last_vert=8;
}

void Circle::createTEdges() // v
{
	_factory->createTEdge("e0");
	_factory->createTEdge("e1");
	_factory->createTEdge("e2");
	_factory->createTEdge("e3");
	_factory->createTEdge("e4");
	_factory->createTEdge("e5");
	_factory->createTEdge("e6");
	_factory->createTEdge("e7");
	_factory->createTEdge("e8");
	_factory->createTEdge("e9");
	_factory->createTEdge("e10");
  _factory->createTEdge("e11");
	last_edge=11;
}

void Circle::createTLinks() // v
{
	_factory->createTLink("l0");
  _factory->createTLink("l1");
	_factory->createTLink("l2");
	_factory->createTLink("l3");
	_factory->createTLink("l4");
	_factory->createTLink("l5");
	_factory->createTLink("l6");
	_factory->createTLink("l7");
	_factory->createTLink("l8");
  _factory->createTLink("l9");
  _factory->createTLink("l10");
	_factory->createTLink("l11");
	_factory->createTLink("l12");
	_factory->createTLink("l13");
  _factory->createTLink("l14");
	_factory->createTLink("l15");
	_factory->createTLink("l16");
	_factory->createTLink("l17");
	_factory->createTLink("l18");
	_factory->createTLink("l19");
	_factory->createTLink("l20");
	_factory->createTLink("l21");
  _factory->createTLink("l22");
	_factory->createTLink("l23");
	last_link=23;
}

void Circle::createTEdgeConditions() // v
{
	_factory->createTEdgeCondition("ec0");
	_factory->createTEdgeCondition("ec1");
	_factory->createTEdgeCondition("ec2");
	_factory->createTEdgeCondition("ec3");
  _factory->createTEdgeCondition("ec4");
	_factory->createTEdgeCondition("ec5");
	_factory->createTEdgeCondition("ec6");
	_factory->createTEdgeCondition("ec7");
	last_edge_cond=7;
}

void Circle::createTFaces() // v
{
	_factory->createTFace("f0");
	_factory->createTFace("f1");
	_factory->createTFace("f2");
	_factory->createTFace("f3");
}

void Circle::createTNodes() // v
{
	_factory->createTNodeV4("n0"); // v
  _factory->createTNodeV4("n1");
  _factory->createTNodeV4("n2");
  _factory->createTNodeV4("n3");
	_factory->createTNodeV4("n4"); // v
  _factory->createTNodeV4("n5");
	_factory->createTNodeV4("n6"); // v
  _factory->createTNodeV4("n7");
  _factory->createTNodeV4("n8");
  _factory->createTNodeV4("n9");
	_factory->createTNodeV4("n10"); // v
  _factory->createTNodeV4("n11");
	_factory->createTNodeV4("n12"); // v
	_factory->createTNodeV4("n13"); // v
  _factory->createTNodeV4("n14");
	_factory->createTNodeV4("n15"); // v
  _factory->createTNodeV4("n16");
  _factory->createTNodeV4("n17");
  _factory->createTNodeV4("n18");
	_factory->createTNodeV4("n19"); // v
  _factory->createTNodeV4("n20");
	_factory->createTNodeV4("n21"); // v
  _factory->createTNodeV4("n22");
  _factory->createTNodeV4("n23");
  _factory->createTNodeV4("n24");
  last_node=24;
}

void Circle::createTPoints()
{
  std::vector<TPointPtr> points_vec;
	points_vec.push_back(_factory->createTPoint("p0", -1.0, -1.0, 0.0, 1.0) ); // v
	points_vec.push_back(_factory->createTPoint("p1", -0.666667, -1.0, 0.0, 1.0)); // v
	points_vec.push_back(_factory->createTPoint("p2", 0, -1, 0.0, 1.0)); // v
	points_vec.push_back(_factory->createTPoint("p3",0.666667,-1 , 0.0, 1.0)); // v
	points_vec.push_back(_factory->createTPoint("p4", 1,-1, 0.0, 1.0)); // v
	points_vec.push_back(_factory->createTPoint("p5", -1, -0.666667, 0.0, 1.0)); // v
	points_vec.push_back(_factory->createTPoint("p6", -0.666667,-0.666667, 0, 1.0)); // v
	points_vec.push_back(_factory->createTPoint("p7",0,-0.666667, 0.0, 1.0)); // v
	points_vec.push_back(_factory->createTPoint("p8", 0.666667,-0.666667, 0.0, 1.0)); // v
  points_vec.push_back(_factory->createTPoint("p9",1,-0.666667 , 0.0, 1.0)); // v
  points_vec.push_back(_factory->createTPoint("p10",-1,0 , 0.0, 1.0)); // v
  points_vec.push_back(_factory->createTPoint("p11",-0.666667,0.0, 0.0, 1.0)); // v
  points_vec.push_back(_factory->createTPoint("p12",0.0,0.0 , 0.0, 1.0)); // v
  points_vec.push_back(_factory->createTPoint("p13",0.666667,0.0 , 0.0, 1.0)); // v
  points_vec.push_back(_factory->createTPoint("p14",1,0.0, 0.0, 1.0)); // v
  points_vec.push_back(_factory->createTPoint("p15",-1,0.666667, 0.0, 1.0)); // v
  points_vec.push_back(_factory->createTPoint("p16",-0.666667,0.666667, 0.0, 1.0)); // v
  points_vec.push_back(_factory->createTPoint("p17",0.0,0.666667, 0.0, 1.0)); // v
  points_vec.push_back(_factory->createTPoint("p18",0.666667,0.666667, 0.0, 1.0)); // v
  points_vec.push_back(_factory->createTPoint("p19",1.0,0.666667, 0.0, 1.0)); // v
  points_vec.push_back(_factory->createTPoint("p20",-1.0,1.0, 0.0, 1.0)); // v
  points_vec.push_back(_factory->createTPoint("p21",-0.666667,1.0, 0.0, 1.0)); // v
  points_vec.push_back(_factory->createTPoint("p22",0.0,1.0, 0.0, 1.0)); // v
  points_vec.push_back(_factory->createTPoint("p23",0.666667,1.0, 0.0, 1.0)); // v
  points_vec.push_back(_factory->createTPoint("p24",1.0,1.0, 0.0, 1.0)); // v
	for (unsigned i=0; i< points_vec.size(); i++) {
		points_x.push_back(points_vec.at(i)->getX());
		points_y.push_back(points_vec.at(i)->getY());
	}
}

void Circle::patchTVertices()
{
	_factory->patchTVertexByVertices("v0", "v3", "", "", "v1"); // v
	_factory->patchTVertexByVertices("v1", "v4", "v0", "", "v2"); // v
	_factory->patchTVertexByVertices("v2", "v5", "v1", "", ""); // v
	_factory->patchTVertexByVertices("v3", "v6", "", "v0", "v4"); // v
	_factory->patchTVertexByVertices("v4", "v7", "v3", "v1", "v5"); // v
	_factory->patchTVertexByVertices("v5", "v8", "v4", "v2", ""); // v
	_factory->patchTVertexByVertices("v6", "", "", "v3", "v7"); // v
	_factory->patchTVertexByVertices("v7", "", "v6", "v4", "v8"); // v
	_factory->patchTVertexByVertices("v8", "", "v7", "v5", ""); // v
}

void Circle::patchTEdges()
{
	_factory->patchTEdge("e0", "v0", "v1", "f0", ""); // v
	_factory->patchTEdge("e1", "v1", "v2", "f1", ""); // v
	_factory->patchTEdge("e2", "v3", "v4", "f2", "f0"); // v
	_factory->patchTEdge("e3", "v4", "v5", "f3", "f1"); // v
	_factory->patchTEdge("e4", "v6", "v7", "", "f2"); // v
	_factory->patchTEdge("e5", "v7", "v8", "", "f3"); // v
	_factory->patchTEdge("e6", "v3", "v0", "f0", ""); // v
	_factory->patchTEdge("e7", "v6", "v3", "f2", ""); // v
	_factory->patchTEdge("e8", "v4", "v1", "f1", "f0"); // v
	_factory->patchTEdge("e9", "v7", "v4", "f3", "f2"); // v
	_factory->patchTEdge("e10", "v5", "v2", "", "f1"); // v
	_factory->patchTEdge("e11", "v8", "v5", "", "f3"); // v
}

void Circle::patchTLinks()
{
	_factory->patchTLink("l0", "e0", true); // v
	_factory->patchTLink("l1", "e0", false); // v
	_factory->patchTLink("l2", "e1", true); // v
	_factory->patchTLink("l3", "e1", false); // v
	_factory->patchTLink("l4", "e2", true); // v
	_factory->patchTLink("l5", "e2", false); // v
	_factory->patchTLink("l6", "e3", true); // v
	_factory->patchTLink("l7", "e3", false); // v
	_factory->patchTLink("l8", "e4", true); // v
	_factory->patchTLink("l9", "e4", false); // v
	_factory->patchTLink("l10", "e5", true); // v
	_factory->patchTLink("l11", "e5", false); // v
	_factory->patchTLink("l12", "e6", true); // v
	_factory->patchTLink("l13", "e6", false); // v
	_factory->patchTLink("l14", "e7", true); // v
	_factory->patchTLink("l15", "e7", false); // v
	_factory->patchTLink("l17", "e8", false); // v
	_factory->patchTLink("l16", "e8", true); // v
	_factory->patchTLink("l19", "e9", false); // v
	_factory->patchTLink("l18", "e9", true); // v
	_factory->patchTLink("l23", "e11", false); // v
	_factory->patchTLink("l22", "e11", true); // v
	_factory->patchTLink("l21", "e10", false); // v
	_factory->patchTLink("l20", "e10", true); // v
}

void Circle::patchTEdgeConditions() // v
{
	_factory->patchTEdgeCondition("ec0", "e0", true);
	_factory->patchTEdgeCondition("ec1", "e1", true);
	_factory->patchTEdgeCondition("ec2", "e4", true);
	_factory->patchTEdgeCondition("ec3", "e5", true);
	_factory->patchTEdgeCondition("ec4", "e6", true);
	_factory->patchTEdgeCondition("ec5", "e7", true);
	_factory->patchTEdgeCondition("ec6", "e10", true);
	_factory->patchTEdgeCondition("ec7", "e11", true);
}


void Circle::patchTFaces()

{
  std::vector<std::string> link_loop;
  std::vector<std::string> nodes;

	link_loop << "l0" << "l16" << "l5" << "l13" ;
	_factory->patchTFace("f0", link_loop, nodes); // v
	link_loop.clear();

	link_loop  <<"l2" << "l20" << "l7" <<"l17";
	_factory->patchTFace("f1", link_loop, nodes); // v
	link_loop.clear();

	link_loop << "l4" << "l18" << "l9" << "l15";
	_factory->patchTFace("f2", link_loop, nodes); // v
	link_loop.clear();

	link_loop << "l6" << "l22" << "l11" << "l19";
	_factory->patchTFace("f3", link_loop, nodes); // v
	link_loop.clear();

	nodes.clear();
}

void Circle::patchTNodes()
{
	//////////////////////////////////////////////////////////////////////////
	// ???
	_factory->patchTNodeV4("n0", "v6", "p20",  "", "", "n2", "n1"); // v
  _factory->patchTNodeV4("n1", "v6", "p21",  "", "n0", "n3", "n4");
  _factory->patchTNodeV4("n2", "v6", "p15",  "n0", "", "n10", "n3");
  _factory->patchTNodeV4("n3", "v6", "p16",  "n1", "n2", "n10", "n4");
	_factory->patchTNodeV4("n4", "v7", "p22", "", "n1", "n5", "n6"); // v
  _factory->patchTNodeV4("n5", "v7", "p17", "n4", "n1", "n12", "n6");
	_factory->patchTNodeV4("n6", "v8", "p23", "", "n4", "n8", "n7"); // v
  _factory->patchTNodeV4("n7", "v8", "p24", "", "n6", "n9", "");
  _factory->patchTNodeV4("n8", "v8", "p18", "n6", "n4", "n14", "n9");
  _factory->patchTNodeV4("n9", "v8", "p19", "n7", "n8", "n14", "");
	_factory->patchTNodeV4("n10", "v3", "p10", "n2", "", "n15", "n11"); // v
  _factory->patchTNodeV4("n11", "v3", "p11", "n2", "n10", "n15", "n12");
	_factory->patchTNodeV4("n12", "v4", "p12", "n5", "n11", "n19", "n13"); // v
	_factory->patchTNodeV4("n13", "v5", "p13", "n9", "n12", "n22", "n14"); // v
  _factory->patchTNodeV4("n14", "v5", "p14", "n9", "n13", "n22", "");
	_factory->patchTNodeV4("n15", "v0", "p5", "n10", "", "n17", "n16"); // v
  _factory->patchTNodeV4("n16", "v0", "p6", "n10", "n15", "n18", "n20");
  _factory->patchTNodeV4("n17", "v0", "p0", "n15", "", "", "n18");
  _factory->patchTNodeV4("n18", "v0", "p1", "n16", "n17", "", "n20");
	_factory->patchTNodeV4("n19", "v1", "p7", "n12", "n18", "n20", "n23"); // v
  _factory->patchTNodeV4("n20", "v1", "p2", "n19", "n18", "", "n23");
	_factory->patchTNodeV4("n21", "v2", "p8", "n14", "n20", "n23", "n22"); // v
  _factory->patchTNodeV4("n22", "v2", "p9", "n14", "n21", "n24", "");
  _factory->patchTNodeV4("n23", "v2", "p3", "n21", "n20", "", "n24");
  _factory->patchTNodeV4("n24", "v2", "p4", "n22", "n23", "", "");
}

void Circle::patchTPoints() // v
{
	_factory->patchTPoint("p0", "n17");
  _factory->patchTPoint("p1", "n18");
  _factory->patchTPoint("p2", "n20");
  _factory->patchTPoint("p3", "n23");
	_factory->patchTPoint("p4", "n24");
  _factory->patchTPoint("p5", "n15");
	_factory->patchTPoint("p6", "n16");
  _factory->patchTPoint("p7", "n19");
  _factory->patchTPoint("p8", "n21");
  _factory->patchTPoint("p9", "n22");
	_factory->patchTPoint("p10", "n10");
  _factory->patchTPoint("p11", "n11");
	_factory->patchTPoint("p12", "n12");
	_factory->patchTPoint("p13", "n13");
  _factory->patchTPoint("p14", "n14");
	_factory->patchTPoint("p15", "n2");
  _factory->patchTPoint("p16", "n3");
  _factory->patchTPoint("p17", "n5");
  _factory->patchTPoint("p18", "n8");
	_factory->patchTPoint("p19", "n9");
  _factory->patchTPoint("p20", "n0");
	_factory->patchTPoint("p21", "n1");
  _factory->patchTPoint("p22", "n4");
  _factory->patchTPoint("p23", "n6");
  _factory->patchTPoint("p24", "n7");
}

void Circle::patchTSpline() // v
{
	_factory->patchTSpline("circle", "image", "nodes", "points");
}

void Circle::patchTImage()
{
	std::vector<std::string> faces, links, edges, vertices;
	_factory->findTObjectNames(faces, TSPLINE::E_TFACE);
	_factory->findTObjectNames(links, TSPLINE::E_TLINK);
	_factory->findTObjectNames(edges, TSPLINE::E_TEDGE);
	_factory->findTObjectNames(vertices, TSPLINE::E_TVERTEX);
	_factory->patchTImage("image", faces, links, edges, vertices);
}

void Circle::patchTConnect()
{
	std::vector<std::string> nodes;
	_factory->findTObjectNames(nodes, TSPLINE::E_TNODE);
	_factory->patchTConnect("nodes", nodes);
}

void Circle::patchTPointset()
{
	std::vector<std::string> points;
	_factory->findTObjectNames(points, TSPLINE::E_TPOINT);
	_factory->patchTPointset("points", points);
}

void Circle::prepareTObjects()
{
	_factory->prepareTNodeHalfLinkages();
      std::cout<<"hi"<<endl;
	_factory->prepareTJunctions();
      std::cout<<"hi"<<endl;
	_factory->prepareImageConnect();
}

TSplinePtr Circle::findTSpline()
{
	return _factory->findTSpline();
}

TGroupPtr Circle::findTGroup()
{
	return _factory->findTGroup();
}

void Circle::findTFaceNames( std::vector<std::string> &faces )
{
	_factory->findTObjectNames(faces, TSPLINE::E_TFACE);
}

/* Call extractUVKnotsFromTNodeV4 from extractor.h to find the local u,v knots.
Then prints them */

void Circle::extractUVKnotsFromTNodeV4()
{
  /*
	std::vector<Real> u_knot, v_knot;
	std::vector<Real> u,v;
	std::vector<TNodeV4Ptr> nodes_chosen{n0};

	for (unsigned int i = 0; i < nodes_chosen.size(); i++) {
		_textractor->extractUVKnotsFromTNodeV4(nodes_chosen.at(i), u, v);
		std::cout << "for node:" << i << '\n';
		std::cout << "u knot is: " << '\n';
		for (unsigned int j = 0; j < u.size(); j++) {
			std::cout << u.at(j) << ' ';
		}
		std::cout << "" << '\n';
    std::cout << "for node:" << i << '\n';
		std::cout << "v knot is: " << '\n';
		for (unsigned int j = 0; j < v.size(); j++) {
			std::cout << v.at(j) << ' ';
		}
		std::cout << "" << '\n';
    v_knot=v;
    v.clear();
    u_knot=u;
		u.clear();
	}
  */
}


void Circle::createNewNode(const Real s_new,const Real tau_new, unsigned int* index){
  std::string new_knot_vname={"v"};
	std::string new_edge_name={"e"};
	std::string new_tlink_name={"l"};
  std::string new_flink_name={"l"};
	std::string new_face_name={"f"};
	std::string new_knot_nname={"n"};
	std::string new_point_name={"p"};
	std::string new_edge_cond_name={"ec"};
	std::string new_name;
  bool condition;

  /* Find between which verices is the new node */
//  unsigned int j=-1;
//  do{
//    j++;
//  }while (!inBetween(vertices_vec[j]->getS(), vertices_vec[j+1]->getS(), s_new));

//  if ( (vertices_vec[j]->getS()==0) || (vertices_vec[j]->getS()==1) ||
//       (vertices_vec[j]->getT()==0) || (vertices_vec[j]->getT()==1) ) {
//       condition=true;
  //     }

  last_vert++;
  new_name=std::to_string(last_vert);
  new_knot_vname.append(new_name);


//  *index=j;
}

Real** Circle::computeTMatrix(Real s_new, int np, std::vector<Real> &u_knot){
  std::vector<double> u_knot_bar;
  double** map;
  double denom1,denom2,numer1,numer2;

  /*Contruct the new u_knot_vector called u_knot_bar */
	for(unsigned j=0; j<u_knot.size(); j++){
		u_knot_bar.push_back(u_knot.at(j));
	}
	u_knot_bar.push_back(s_new);
	sort( u_knot_bar.begin(), u_knot_bar.end() );

  /*Allocate space for T0, T1, T2 matrix */
  map = new double*[np+1];
  for (int i = 0; i < (np+1); ++i) {
    map[i] = new double[np+2];
  }

  /*initialize the matrices with zeros */
  for (int i=0; i<(np+1); i++){
    for(int j=0; j<np+2; j++){
        map[i][j]=0;
    }
  }

  /*Compute Tij^0 */
  for (int i=0; i<(np+1); i++){
    for(int j=0; j<(np+2); j++){
      if ( (u_knot_bar.at(i)==0)  ){
        map[i][i]=1;
      }
      if( (u_knot_bar.at(i)!=0) && (u_knot_bar.at(i) >= u_knot.at(j)) && (u_knot_bar.at(i)< u_knot.at(j+1))) {
        map[i][j]=1;
      }
    }
  }

  /*Compute T1 */
  for (int q=1; q<3; q++){
    int k=1;
    for(int i=0; i<np+1; i++){
      for(int j=0; j<np+k; j++){
        denom1=(u_knot[j+q]-u_knot[j]);
        denom2=(u_knot[j+q+1]-u_knot[j+1]);
        numer1=(u_knot_bar[i+q]-u_knot[j]);
        numer2=(u_knot[j+q+1]-u_knot_bar[i+q]);
        if ( (denom2==0) && (denom1==0) ) {
          map[i][j]=0;
        }
        else if ( (denom1==0) ){
          map[i][j]= (numer2/ denom2)*map[i][j+1]+0;
        }
        else if ( (denom2==0)  ){
          map[i][j]= (numer1/ denom1)*map[i][j]+0;
        }
        else{
          map[i][j]= (numer1/ denom1)*map[i][j]+(numer2/denom2)*map[i][j+1];
        }
      }
    }
    k--;
  }

  /*Normalization */
  for (int i=0; i<np+1; i++){
    double sum=0;
    for (int j=0; j<np; j++){
      sum=sum+map[i][j];
    }
    if (sum==0){
      map[i][i]=1;
    }
  }
  return map;
}

void Circle::computeNewControlPoint(){
	std::vector<Real> new_points_x, new_points_y;
  for(unsigned int i=0; i<points_x.size()+1; i++){
    Real sumx=0;
    Real sumy=0;
    for(unsigned int j=0; j<points_x.size(); j++){
      sumx=sumx+map[i][j]*points_x[j];
      sumy=sumy+map[i][j]*points_y[j];
    }
    new_points_x.push_back(sumx);
    new_points_y.push_back(sumy);
  }
  std::cout<<"size is: "<<new_points_x.size()<<endl;
  for(unsigned i=0; i<new_points_x.size(); i++){
    std::cout<<new_points_x[i]<<":"<<new_points_y[i]<<endl;
  }
}

void Circle::insertNewNode(unsigned int index){

}
