#include "node.h"
#include <fstream>
#include <iostream>
#include <iterator>
#include <regex>
#include <string>


GraphModel::Node::Node(std::string note_path)
{
	std::ifstream input;

	input.open(note_path);
	m_content = std::string(std::istreambuf_iterator<char>{input}, {});
	input.close();

	int filename_start = note_path.find_last_of('/') + 1;
	int filename_end = note_path.find_last_of('.');

	m_filename = note_path.substr(filename_start, filename_end - filename_start);
}

void GraphModel::Node::RecalculateLinks(std::map<std::string, Node> &nodemap)
{
	m_links.clear();
	const std::regex zettel_link_regex("\\[\\[(\\d{6}-\\d{4}[a-z]*)\\|[^\\]]*\\]\\]");
	std::sregex_iterator content_begin = std::sregex_iterator(m_content.begin(), m_content.end(), zettel_link_regex);
	std::sregex_iterator content_end = std::sregex_iterator();

	for (std::sregex_iterator i = content_begin; i != content_end; i++) {
		std::string link_filename = (*i)[1].str();

		auto node = nodemap.find(link_filename);

		if (node != nodemap.end()) {
			Node* link = &node->second;
			std::cout << "Found link to " << link->m_filename << " in " << m_filename << std::endl;
			m_links.push_back(link);
		}
	}

	std::cout << m_filename << ": " << m_links.size() << std::endl;

}
