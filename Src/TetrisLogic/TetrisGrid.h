#ifndef TETRISGRID_H
#define TETRISGRID_H

#include "TetrisGfxBlock.h"
#include "TetrisPiece.h"
#include "../Graphics/GfxImage.h"

class TetrisGrid
{
	private :
	
		const int m_width, m_height;
		const int m_posX, m_posY;
		
		TetrisGfxBlock** m_pBlocksArray;
	
		GfxImageSharedPtr m_pGfxGrid;
		
	public :
	
		TetrisGrid(int width, int height, int posX, int posY);
		~TetrisGrid();
		
		void AddBlock(int i, int j, ePieceType pieceType);
		void MoveBlock(int i1, int j1, int i2, int j2);
		void RemoveBlock(int i, int j);
		TetrisGfxBlock* GetBlock(int i, int j) const;
		
		void InitPosition(TetrisPiece *pPiece);
		//void InitPosition(TetrisGfxBlock *pBlock);
		
	private :
	
		void AllocateBlocksArray();
		void DeallocateBlocksArray();
};

#endif