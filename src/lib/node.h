#ifndef GK_NODE_H
#define GK_NODE_H
#include <iostream>
#include <map>
#include <vector>

namespace GraphModel
{
class Node
{
  public:
	Node(std::string note_path);
	void RecalculateLinks(std::map<std::string, Node> &nodemap);
      std::string m_filename;

  protected:
	std::string m_content;
	std::vector<Node *> m_links;
};
} // namespace GraphModel

#endif
