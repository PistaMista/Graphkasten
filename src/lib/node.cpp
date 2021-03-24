#include "node.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>
#include <string>

const std::regex GraphModel::Node::zettel_link_regex = std::regex("\\[\\[(\\d{6}-\\d{4}[a-z]*)\\|[^\\]]*\\]\\]");
const std::regex GraphModel::Node::title_regex = std::regex("^\\%title ([^\\n]+)\\n");

GraphModel::Node::Node(std::string note_path)
{
	// Load the note contents
	std::ifstream input;

	input.open(note_path);
	m_content = std::string(std::istreambuf_iterator<char>{input}, {});
	input.close();

	// Extract the filename of the note
	int filename_start = note_path.find_last_of('/') + 1;
	int filename_end = note_path.find_last_of('.');

	m_filename = note_path.substr(filename_start, filename_end - filename_start);

	// Extract the title of the note (if it has one)
	std::smatch match;
	std::regex_search(m_content, match, title_regex);

	m_title = match.size() == 2 ? match.str(1) : m_filename;
}

void GraphModel::Node::RecalculateLinks(std::map<std::string, Node> &nodemap)
{
	m_links.clear();
	std::sregex_iterator links_begin = std::sregex_iterator(m_content.begin(), m_content.end(), zettel_link_regex);
	std::sregex_iterator links_end = std::sregex_iterator();

	for ( std::sregex_iterator links = links_begin; links != links_end; links++ )
	{
		std::string link_filename = (*links)[1].str();

		auto node = nodemap.find(link_filename);

		if ( node != nodemap.end() )
		{
			Node *link = &node->second;
			m_links.push_back(link);
		}
	}
}

std::string GraphModel::Node::getFilename()
{
	return m_filename;
}

std::string GraphModel::Node::getTitle()
{
	return m_title;
}

std::vector<GraphModel::Node *> GraphModel::Node::getLinks()
{
	return std::vector<GraphModel::Node *>(m_links);
}
