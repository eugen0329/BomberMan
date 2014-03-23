#ifndef _CELL_HPP_
#define _CELL_HPP_

class Cell;
typedef Cell cell_t;
typedef char cellID_t;

class Cell {
private:
    bool solid;
    cellID_t cellID;
public:
    friend class GameMap;
    Cell(cellID_t cellID, bool solid = false);
    ~Cell();
    inline cellID_t getCellID()
    {
        return this->cellID;
    }
    inline bool isSolid()
    {
        return solid;
    }
    
};

#endif /* end of include guard: _CELL_HPP_ */
