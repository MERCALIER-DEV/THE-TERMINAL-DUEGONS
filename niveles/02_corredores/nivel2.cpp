#include "nivel2.h"
#include "sit2_1.h"
#include "sit2_2.h"
#include "sit2_3.h"
#include "sit2_4.h"
#include "sit2_5.h"

bool jugar_nivel2(){
    return sit2_1() && sit2_2() && sit2_3() && sit2_4() && sit2_5();
}