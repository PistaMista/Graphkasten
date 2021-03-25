#include "graph.h"
#include "graphkasten.h"
#include "node.h"
#include <filesystem>
#include <fstream>
#include <iostream>

GraphModel::Graph::Graph(std::string folder_path)
{
	for ( auto &file : std::filesystem::directory_iterator(folder_path) )
	{
		std::string path = file.path();

		if ( path.ends_with(".wiki") && file.is_regular_file() )
		{
			Node node = Node(path);
			m_nodemap.insert(std::pair<std::string, Node>{node.getFilename(), node});
		}
	}

	for ( auto &node : m_nodemap )
		node.second.RecalculateLinks(m_nodemap);
}

std::vector<GraphModel::Node *> GraphModel::Graph::GetNodes()
{
	std::vector<GraphModel::Node *> nodes;
	for ( auto elem : m_nodemap )
		nodes.push_back(&elem.second);

	return nodes;
}
