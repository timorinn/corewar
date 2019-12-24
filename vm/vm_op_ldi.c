//
// Created by Katharine Psylocke on 24/12/2019.
//

#include "vm.h"

bool	vm_op_ldi(uint8_t map[MEM_SIZE][4], t_cursor *car)
{
	return (op_load_i(map, car, false));
}
