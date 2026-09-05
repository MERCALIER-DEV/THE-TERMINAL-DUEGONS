#include "nivel4.h"
#include "sit4_1.h"
#include "sit4_2.h"
#include "sit4_3.h"
#include "sit4_4.h"
#include "sit4_5.h"

bool jugar_nivel4(){
    return sit4_1() && sit4_2() && sit4_3() && sit4_4() && sit4_5();
}


