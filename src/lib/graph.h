#ifndef GK_GRAPH_H
#define GK_GRAPH_H
#include "lib/node.h"
#include <map>
#include <string>

namespace GraphModel
{
class Graph final
{
  public:
	Graph(std::string folder_path);

  private:
	std::map<std::string, Node> m_nodemap;
};
} // namespace GraphModel

#endif
