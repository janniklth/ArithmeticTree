#ifndef ARITHMETIC_TREE_VISUALIZER_HPP
#define ARITHMETIC_TREE_VISUALIZER_HPP


#include "Token Classes/Token.hpp"

#include "iostream"


/*
 * Visualisierung eines arithmetischen Binärbaums
 */


class Visualizer
{
public:
	
    static const int REGULAR = 1; // Darstellung mit gleichen Abständen zwischen Knoten
    static const int BINARY = 2;  // Darstellung mit fortlaufend halbierten Abständen

    /*
     * Erzeugt das Text-/Grafikfenster.
     * 
     * Parameter: t darzustellender Baum
     * Parameter: s Spacing: Visualizer.REGULAR oder Visualizer.BINARY
     */
    Visualizer(Token *t, int s)
	{
        m_tree = t;
        m_spacing = s;
    
		// ...
    }
    
    /*
     * Zeichnet einen Baumknoten.
     * 
     * Parameter: x x-Position (Mittelpunkt des Knotens)
     * Parameter: y y-Position (Mittelpunkt des Knotens)
     * Parameter: node darzustellender Baumknoten
     */
    void drawSingleNode(int x, int y, Token *node) 
	{

		// ...
	}
    
    /*
     * Zeichnet einen Baum mit gleichmäßigem Abstand zwischen Knoten.
     * 
     * Parameter: t darzustellender Baum
     */
    void drawTreeReg(Token *t) 
	{
        drawTreeReg(t, 0, 0);
    }
    
    /*
     * Zeichnet einen Baum mit gleichmäßigem Abstand zwischen Knoten.
     * 
     * Parameter: t darzustellender Baum
     * Parameter: depth aktuelle Tiefenebene im Baum
     * Parameter: xorig x-Position des Vaterknotens
     */
    void drawTreeReg(Token *t, int depth, int xorig) 
	{
		// ...
	}
    
    /*
     * Zeichnet einen Baum mit fortlaufend halbierten Abstaenden.
     * 
     * Parameter: t darzustellender Baum
     */
    void drawTreeBin(Token *t) 
	{
        drawTreeBin(t, 0, "", 0);
    }

    /*
     * Zeichnet einen Baum mit fortlaufend halbierten Abstaenden.
     * 
     * Parameter: t darzustellender Baum
     * Parameter: depth aktuelle Tiefenebene im Baum
     * Parameter: history Pfad bestehend aus "l" und "r" von der Wurzel zum aktuellen Knoten
     * Parameter: xorig x-Position des Vaterknotens
     */
	void drawTreeBin(Token *t, int depth, string history, int xorig) 
	{
		// ...
	}

    /*
     * Zeichnen des Baums und Anzeige des Grafikfensters
     */
    void paint() 
	{

		if (m_spacing == REGULAR)
		{
            Order* o = new Order(); // Zaehler
            m_tree->order(o); // Baum in Infix-Reihenfolge nummerieren
            drawTreeReg(m_tree);
        } else 
			drawTreeBin(m_tree);
    }

    /// simple test method to print a tree
    /// @param root: the root node of tree to print
    void printTree(Token* root, std::string prefix = "", bool isLast = true)
    {
        if (root == nullptr)
            return;

        std::cout << prefix;

        if (isLast)
        {
            std::cout << "└──";
            prefix += "    ";
        }
        else
        {
            std::cout << "├──";
            prefix += "│   ";
        }

        std::cout << " " << root->getValue() << std::endl;

        printTree(root->getRight(), prefix, false);
        printTree(root->getLeft(), prefix, true);

    }


private:
    Token *m_tree;
    int m_spacing;
    int m_width;
    int m_height;
};

#endif // ARITHMETIC_TREE_VISUALIZER_HPP