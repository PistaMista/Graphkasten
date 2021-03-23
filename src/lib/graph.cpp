#include "graph.h"
#include "graphkasten.h"
#include <filesystem>
#include <fstream>
#include <iostream>

GraphModel::Graph::Graph(std::string folder_path)
{
	for ( auto &file : std::filesystem::directory_iterator(folder_path) )
	{
		std::string path = file.path();

		if ( path.ends_with(".wiki") )
		{
			Node node = Node(path);
			m_nodemap.insert(std::pair<std::string, Node>{node.m_filename, node});
		}
	}

	for ( auto &node : m_nodemap )
		node.second.RecalculateLinks(m_nodemap);
}
