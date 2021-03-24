#ifndef GK_NODE_H
#define GK_NODE_H
#include <iostream>
#include <map>
#include <regex>
#include <vector>

namespace GraphModel
{
class Node
{
  public:
	Node(std::string note_path);
	void RecalculateLinks(std::map<std::string, Node> &nodemap);
	std::string getFilename();
	std::string getTitle();
	std::vector<Node *> getLinks();

	static const std::regex zettel_link_regex;
	static const std::regex title_regex;

  protected:
	std::string m_content;
	std::vector<Node *> m_links;

  private:
	std::string m_filename;
	std::string m_title;
};
} // namespace GraphModel

#endif
