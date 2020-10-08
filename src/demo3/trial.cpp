/*
TSPLINE -- A T-spline object oriented package in C++
Copyright (C) 2015-  Wenlei Xiao

This library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as
published by the Free Software Foundation; either version 2.1 of the
License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA


Report problems and direct all questions to:

Wenlei Xiao, Ph.D
School of Mechanical Engineering and Automation
Beihang University (Beijing University of Aeronautics and Astronautics)
D-315, New Main Building,
Beijing, P.R. China, 100191

email: xiaowenlei@buaa.edu.cn
-------------------------------------------------------------------------------
Revision_history:

2015/04/08: Wenlei Xiao
   - xxxxx.
-------------------------------------------------------------------------------
*/

/*!
  @file demo.cpp
  @brief A demo file.

  Demos for T-spline, etc.
*/

#include "trial.h"

#ifdef use_namespace
using namespace TSPLINE;
#endif

extern std::vector<std::string>& operator<<(std::vector<std::string> &container, const std::string &value);

Trial::Trial()
{
	_factory = makePtr<TFactory>();
	createTrial();
}

void Trial::createTrial()
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

void Trial::createTSpline()
{
	_factory->createTSpline("trial");
}

void Trial::createTImage()
{
	_factory->createTImage("image");
}

void Trial::createTConnect()
{
	_factory->createTConnect("nodes");
}

void Trial::createTPointset()
{
	_factory->createTPointset("points");
}

void Trial::createTVertices()
{
	_factory->createTVertex("v0", 0.0, 0.0); // v
	_factory->createTVertex("v1", 1.0, 0.0); // v
	_factory->createTVertex("v2", 1.0, 1.0); // v
	_factory->createTVertex("v3", 0.0, 1.0); // v
	//_factory->createTVertex("v4", 0.5, 0.0); // v
}

void Trial::createTEdges() // v
{
	_factory->createTEdge("e0");
	_factory->createTEdge("e1");
	_factory->createTEdge("e2");
	_factory->createTEdge("e3");
	//_factory->createTEdge("e4");
}

void Trial::createTLinks() // v
{
	_factory->createTLink("l0");
  _factory->createTLink("l1");
	_factory->createTLink("l2");
	_factory->createTLink("l3");
	_factory->createTLink("l4");
	_factory->createTLink("l5");
	_factory->createTLink("l6");
	_factory->createTLink("l7");
	//_factory->createTLink("l8");
	//_factory->createTLink("l9");

}

void Trial::createTEdgeConditions() // v
{
	_factory->createTEdgeCondition("ec0");
	_factory->createTEdgeCondition("ec1");
	_factory->createTEdgeCondition("ec2");
	_factory->createTEdgeCondition("ec3");
//	_factory->createTEdgeCondition("ec4");
}

void Trial::createTFaces() // v
{
	_factory->createTFace("f0");
}

void Trial::createTNodes() // v
{
	_factory->createTNodeV4("n0-0");//v
	_factory->createTNodeV4("n0-1");
	_factory->createTNodeV4("n0-2");
	_factory->createTNodeV4("n0-3");
  _factory->createTNodeV4("n1-0");//v
	_factory->createTNodeV4("n1-1");
	_factory->createTNodeV4("n1-2");
	_factory->createTNodeV4("n1-3");
  _factory->createTNodeV4("n2-0"); //v
	_factory->createTNodeV4("n2-1");
	_factory->createTNodeV4("n2-2");
	_factory->createTNodeV4("n2-3");
  _factory->createTNodeV4("n3-0"); //v
	_factory->createTNodeV4("n3-1");
	_factory->createTNodeV4("n3-2");
	_factory->createTNodeV4("n3-3");
	//_factory->createTNodeV4("n4-0");//v
	//_factory->createTNodeV4("n4-1");
	//_factory->createTNodeV4("n4-2");
//	_factory->createTNodeV4("n4-3");

}

void Trial::createTPoints()
{
	_factory->createTPoint("p0-0", 0.0, 0.0, 0.0, 1.0); // v
	_factory->createTPoint("p0-1", 0.0, 0.0, 0.0, 1.0);
	_factory->createTPoint("p0-2", 0.0, 0.0, 0.0, 1.0);
	_factory->createTPoint("p0-3", 0.0, 0.0, 0.0, 1.0);
  _factory->createTPoint("p1-0", 1.0, 0.0, 0.0, 1.0); // v
	_factory->createTPoint("p1-1", 1.0, 0.0, 0.0, 1.0);
	_factory->createTPoint("p1-2", 1.0, 0.0, 0.0, 1.0);
	_factory->createTPoint("p1-3", 1.0, 0.0, 0.0, 1.0);
  _factory->createTPoint("p2-0", 1.0, 1.0, 0.0, 1.0);//v
	_factory->createTPoint("p2-1", 1.0, 1.0, 0.0, 1.0);
	_factory->createTPoint("p2-2", 1.0, 1.0, 0.0, 1.0);
	_factory->createTPoint("p2-3", 1.0, 1.0, 0.0, 1.0);
  _factory->createTPoint("p3-0", 0.0, 1.0, 0.0, 1.0);//v
	_factory->createTPoint("p3-1", 0.0, 1.0, 0.0, 1.0);
	_factory->createTPoint("p3-2", 0.0, 1.0, 0.0, 1.0);
	_factory->createTPoint("p3-3", 0.0, 1.0, 0.0, 1.0);
	//_factory->createTPoint("p4-0", 0.5, 0.0, 0.0, 1.0);//v
	//_factory->createTPoint("p4-1", 0.5, 0.0, 0.0, 1.0);
	//_factory->createTPoint("p4-2", 0.5, 0.0, 0.0, 1.0);
	//_factory->createTPoint("p4-3", 0.5, 0.0, 0.0, 1.0);
}

void Trial::patchTVertices()
{
	_factory->patchTVertexByVertices("v0", "v3", "", "", "v1"); // v
	_factory->patchTVertexByVertices("v1", "v2", "v1", "", ""); // v
	_factory->patchTVertexByVertices("v2", "", "v3", "v1", ""); // v
	_factory->patchTVertexByVertices("v3", "", "", "v0", "v2"); // v
}

void Trial::patchTEdges()
{
	_factory->patchTEdge("e0", "v0", "v1", "f0", ""); // v
	_factory->patchTEdge("e1", "v2", "v1", "", "f0"); // v
	_factory->patchTEdge("e2", "v3", "v2", "", "f0"); // v
	_factory->patchTEdge("e3", "v3", "v0", "f0", ""); // v
	//_factory->patchTEdge("e4", "v4", "v1", "f0", ""); // v
}

void Trial::patchTLinks()
{
	_factory->patchTLink("l0", "e0", true); // v
	_factory->patchTLink("l1", "e0", false); // v
	_factory->patchTLink("l2", "e1", true); // v
	_factory->patchTLink("l3", "e1", false); // v
	_factory->patchTLink("l4", "e2", true); // v
	_factory->patchTLink("l5", "e2", false); // v
	_factory->patchTLink("l6", "e3", true); // v
	_factory->patchTLink("l7", "e3", false); // v
//	_factory->patchTLink("l8", "e4", true); // v
//	_factory->patchTLink("l9", "e4", false); // v
}

void Trial::patchTEdgeConditions() // v
{
	_factory->patchTEdgeCondition("ec0", "e0", true);
	_factory->patchTEdgeCondition("ec1", "e1", true);
	_factory->patchTEdgeCondition("ec2", "e2", true);
	_factory->patchTEdgeCondition("ec3", "e3", true);
	//_factory->patchTEdgeCondition("ec4", "e4", true);
}

void Trial::patchTFaces()
{
	std::vector<std::string> link_loop;
	std::vector<std::string> nodes;

	link_loop << "l0" <<"l3" << "l5" << "l6";
	_factory->patchTFace("f0", link_loop, nodes); // v
	link_loop.clear();

	nodes.clear();
}

void Trial::patchTNodes()
{
	//////////////////////////////////////////////////////////////////////////
	// ???
	_factory->patchTNodeV4("n0-0", "v0", "p0-0",  "n0-3", "", "", "n0-1"); //v
	_factory->patchTNodeV4("n0-1", "v0", "p0-1",  "n0-2", "n0-0", "", "n1-3");
	_factory->patchTNodeV4("n0-2", "v0", "p0-2",  "n3-2", "n0-3", "n0-1", "n1-2");
	_factory->patchTNodeV4("n0-3", "v0", "p0-3",  "n3-3", "", "n0-0", "n0-2");
  _factory->patchTNodeV4("n1-0", "v1", "p1-0",  "n1-1", "n1-3", "", "");//v
	_factory->patchTNodeV4("n1-1", "v1", "p1-1",  "n2-1", "n1-2", "n1-0", "");
	_factory->patchTNodeV4("n1-2", "v1", "p1-2",  "n2-2", "n0-2", "n1-3", "n1-1");
	_factory->patchTNodeV4("n1-3", "v1", "p1-3",  "n1-2", "n0-1", "", "n1-0");
  _factory->patchTNodeV4("n2-0", "v2", "p2-0",  "", "n2-3", "n2-1", "");//v
	_factory->patchTNodeV4("n2-1", "v2", "p2-1",  "n2-0", "n2-2", "n1-1", "");
	_factory->patchTNodeV4("n2-2", "v2", "p2-2",  "n2-3", "n3-2", "n1-2", "n2-1");
	_factory->patchTNodeV4("n2-3", "v2", "p2-3",  "", "n3-1", "n2-2", "n2-0");
  _factory->patchTNodeV4("n3-0", "v3", "p3-0",  "", "", "n3-3", "n3-1");//v
	_factory->patchTNodeV4("n3-1", "v3", "p3-1",  "", "n3-0", "n3-2", "n2-3");
	_factory->patchTNodeV4("n3-2", "v3", "p3-2",  "n3-1", "n3-3", "n0-2", "n2-2");
	_factory->patchTNodeV4("n3-3", "v3", "p3-3",  "n3-0", "", "n0-3", "n3-2");


}

void Trial::patchTPoints() // v
{
	_factory->patchTPoint("p0-0", "n0-0");
	_factory->patchTPoint("p0-1", "n0-1");
	_factory->patchTPoint("p0-2", "n0-2");
	_factory->patchTPoint("p0-3", "n0-3");
	_factory->patchTPoint("p1-0", "n1-0");
	_factory->patchTPoint("p1-1", "n1-1");
	_factory->patchTPoint("p1-2", "n1-2");
	_factory->patchTPoint("p1-3", "n1-3");
	_factory->patchTPoint("p2-0", "n2-0");
	_factory->patchTPoint("p2-1", "n2-1");
	_factory->patchTPoint("p2-2", "n2-2");
	_factory->patchTPoint("p2-3", "n2-3");
	_factory->patchTPoint("p3-0", "n3-0");
	_factory->patchTPoint("p3-1", "n3-1");
	_factory->patchTPoint("p3-2", "n3-2");
	_factory->patchTPoint("p3-3", "n3-3");
}

void Trial::patchTSpline() // v
{
	_factory->patchTSpline("trial", "image", "nodes", "points");
}

void Trial::patchTImage()
{
	std::vector<std::string> faces, links, edges, vertices;
	_factory->findTObjectNames(faces, TSPLINE::E_TFACE);
	_factory->findTObjectNames(links, TSPLINE::E_TLINK);
	_factory->findTObjectNames(edges, TSPLINE::E_TEDGE);
	_factory->findTObjectNames(vertices, TSPLINE::E_TVERTEX);
	_factory->patchTImage("image", faces, links, edges, vertices);
}

void Trial::patchTConnect()
{
	std::vector<std::string> nodes;
	_factory->findTObjectNames(nodes, TSPLINE::E_TNODE);
	_factory->patchTConnect("nodes", nodes);
}

void Trial::patchTPointset()
{
	std::vector<std::string> points;
	_factory->findTObjectNames(points, TSPLINE::E_TPOINT);
	_factory->patchTPointset("points", points);
}

void Trial::prepareTObjects()
{
	_factory->prepareTNodeHalfLinkages();
	_factory->prepareTJunctions();
	_factory->prepareImageConnect();
}

TSplinePtr Trial::findTSpline()
{
	return _factory->findTSpline();
}

TGroupPtr Trial::findTGroup()
{
	return _factory->findTGroup();
}

void Trial::findTFaceNames( std::vector<std::string> &faces )
{
	_factory->findTObjectNames(faces, TSPLINE::E_TFACE);
}
