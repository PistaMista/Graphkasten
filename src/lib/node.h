#ifndef GK_NODE_H
#define GK_NODE_H
#include <iostream>
#include <map>
#include <regex>
#include <vector>

namespace GraphModel
{
/**
 * @brief A representation of a single note within the wiki Graph.
 */
class Node
{
  public:
	/**
	 * @param note_path The path to the note file to model.
	 */
	Node(std::string note_path);

	/**
	 * @brief Recalculates the links of this note to other notes.
	 *
	 * @param nodemap The nodemap containing all of the notes currently loaded into the graph.
	 */
	void RecalculateLinks(std::map<std::string, Node> &nodemap);

	/**
	 * @return The filename of the note file which this node represents.
	 */
	std::string getFilename();

	/**
	 * @return The title of the note.
	 */
	std::string getTitle();

	/**
	 * @return Pointers to the other notes that are linked within the note file.
	 */
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
