#include "complex.h"

#ifndef QUREG_H
#define QUREG_H

using namespace std;

class QuReg {
public:
  //Default constructor.  Size is the size in bits of our register.
  //In our implementation of Shor's algorithm we will need size bits
  //to represent our value for "q" which is a number we have chosen
  //with small prime factors which is between 2n^2 and 3n^2 inclusive
  //where n is the number we are trying to factor.  We envision our
  //the description of our register of size "S" as 2^S complex
  //numbers, representing the probability of finding the register on
  //one of or 2^S base states.  Thus we use an array of size 2^S, of
  //Complex numbers.  Thus if the size of our register is 3 bits
  //array[7] is the probability amplitude of the state |1,1,1>, and
  //array[7] * Complex Conjugate(array[7]) = probability of choosing
  //that state.  We use normalized state vectors thought the
  //simulation, thus the sum of all possible states times their
  //complex conjugates is = 1.
  QuReg(unsigned long long int size); 

  QuReg(); //Default Constructor

  QuReg(const QuReg &); //Copy constructor

  virtual ~QuReg(); //Default destructor.
  
  //Measures our quantum register, and returns the decimal
  //interpretation of the bit string measured.
  unsigned long long int DecMeasure(); 
  
  //Dumps all the information about the quantum register.  This
  //function would not be possible for an actual quantum register, it
  //is only there for debugging.  When verbose != 0 we return every
  //value, when verbose = 0 we return only probability amplitudes
  //which differ from 0.
  void Dump(int verbose) const;

  //Sets state of the qubits using the arrays of complex amplitudes.
  void SetState(Complex *new_state);

  //Sets the state to an equal superposition of all possible states
  //between 0 and number inclusive.
  void SetAverage(unsigned long long int number);

  //Normalize the state amplitudes.
  void Norm(); 
  
  //Get the probability of a given state.  This is used in the
  //discrete Fourier transformation.  In a real quantum computer such
  //an operation would not be possible, on the flip side, it would
  //also not be necessary as you could simply build a DFT gate, and
  //run your superposition through it to get the right answer.
  Complex GetProb(unsigned long long int state) const;

  //Return the size of the register.
  int Size() const;

private:
  unsigned long long int reg_size;
  Complex *State;
};

#endif
