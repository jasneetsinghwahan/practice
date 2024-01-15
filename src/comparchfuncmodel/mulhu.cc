#include <cassert>
#include <cstdint>
#include <climits>
#include <cstddef>
#include <type_traits>
#include "arith.h"


/***
 * description from https://riscv.org/wp-content/uploads/2019/06/riscv-spec.pdf
 * MUL performs an XLEN-bit×XLEN-bit multiplication of rs1 by rs2 and places the lower XLEN bits
 * in the destination register. MULH, MULHU, and MULHSU perform the same multiplication but return the upper XLEN bits of the full 2×XLEN-bit product, for signed×signed, unsigned×unsigned,
 * and signed rs1×unsigned rs2 multiplication, respectively
 * code from: https://github.com/riscv-software-src/riscv-isa-sim/blob/master/riscv/arith.h
*/
uint64_t 
arith::mulhu(uint64_t a, uint64_t b)
{
  uint64_t t;
  uint32_t y1, y2, y3;
  uint64_t a0 = (uint32_t)a, a1 = a >> 32;
  uint64_t b0 = (uint32_t)b, b1 = b >> 32;

  t = a1*b0 + ((a0*b0) >> 32);
  y1 = t;
  y2 = t >> 32;

  t = a0*b1 + y1;

  t = a1*b1 + y2 + (t >> 32);
  y2 = t;
  y3 = t >> 32;

  return ((uint64_t)y3 << 32) | y2;
}