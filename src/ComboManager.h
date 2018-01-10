#ifndef COMBOMANAGER_H
#define COMBOMANAGER_H

#include <cassert>

using namespace std;

#include "ComboTabulator.h"
#include "BlockManager.h"
#include "Block.h"

class Block;

/* static */ class ComboManager {
public:
  static void gameStart (   );
  static void timeStep (   );

  static inline ComboTabulator &newComboTabulator (   )
  {
    int id = findFreeId();
    allocateId(id);
    ComboTabulator &combo = tabulatorStore[id];

    combo.initialize();
    return combo;
  }

  static inline void deleteComboTabulator ( ComboTabulator &combo )
  {
    freeId(combo.id);
  }

  static inline void specialBlockTally ( ComboTabulator &combo, Block &block )
  {
    if (BlockManager::isBaseFlavor(block.flavor)) return;
    combo.special[BlockManager::mapSpecialFlavorToCode(block.flavor)]++;
  }


private:
  static inline int findFreeId (   )
  {
    int n;
    for (n = 0; storeMap[n]; n++);
    return n;
  }

  static inline void allocateId ( int id )
  {
    assert(!storeMap[id]);
    storeMap[id] = true;
    combo_count++;
  }

  static inline void freeId ( int id )
  {
    assert(storeMap[id]);
    storeMap[id] = false;
    combo_count--;
  }

  static ComboTabulator tabulatorStore[GC_COMBO_TABULATOR_STORE_SIZE];
  static bool storeMap[GC_COMBO_TABULATOR_STORE_SIZE];
  static int combo_count;
};

#endif
