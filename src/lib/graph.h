#ifndef GK_GRAPH_H
#define GK_GRAPH_H
#include "lib/node.h"
#include <map>
#include <string>

namespace GraphModel
{
/**
  * @brief A data structure to represent a folder of wiki files as a graph.
  */
class Graph final
{
  public:
	/**
       * @param folder_path The folder of wiki files to convert into a graph model.
       */
	Graph(std::string folder_path);

	/**
       * @brief Gets all the nodes in the graph.
       * @return All the nodes in the graph.
       */
	std::vector<Node *> GetNodes();

  private:
	/**
       * @brief The nodes contained within the graph, indexed by their filename.
       */
	std::map<std::string, Node> m_nodemap;
};
} // namespace GraphModel

#endif
