#include "nivel5.h"
#include "sit5_1.h"
#include "sit5_2.h"
#include "sit5_3.h"
#include "sit5_4.h"
#include "sit5_5.h"

bool jugar_nivel5(){
    return sit5_1() && sit5_2() && sit5_3() && sit5_4() && sit5_5();
}


