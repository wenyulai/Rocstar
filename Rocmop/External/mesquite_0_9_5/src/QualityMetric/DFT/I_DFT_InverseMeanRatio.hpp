/* ***************************************************************** 
    MESQUITE -- The Mesh Quality Improvement Toolkit

    Copyright 2004 Sandia Corporation and Argonne National
    Laboratory.  Under the terms of Contract DE-AC04-94AL85000 
    with Sandia Corporation, the U.S. Government retains certain 
    rights in this software.

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License 
    (lgpl.txt) along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 
    diachin2@llnl.gov, djmelan@sandia.gov, mbrewer@sandia.gov, 
    pknupp@sandia.gov, tleurent@mcs.anl.gov, tmunson@mcs.anl.gov      
   
  ***************************************************************** */

/*! \file I_DFT_InverseMeanRatio.hpp

Header file for the Mesquite::I_DFT_InverseMeanRatio class

  \author Michael Brewer
  \date   2005-Mar-04
 */


#ifndef I_DFT_INVERSE_MEAN_RATIO_hpp
#define I_DFT_INVERSE_MEAN_RATIO_hpp

#include "I_DFT.hpp"

namespace Mesquite
{
  
  /*! \class I_DFT_InverseMeanRatio
    \brief I_DFT metric with mAlpha = 1/3, mBeta = 0.0, mGamma = 2/3

The form of this metric is as follows (taken from I_DFTFamilyFunctions.hpp,
see that file for more detail): \n

                  mAlpha * || A*inv(W) - mBeta * I ||_F^2                    \n
   ------------------------------------------------------------------        \n
   0.5^(mGamma)*(det(A*inv(W)) + sqrt(det(A*inv(W))^2 + 4*delta^2))^(mGamma) \n

The default for data members (corresponding to the variables above): \n

      mAlpha = 1/3 \n
      mBeta = 0.0 \n
      mGamma = 2/3; \n

delta, above, is not used.

*/
  
  class I_DFT_InverseMeanRatio : public I_DFT
  {
  public:
    
    I_DFT_InverseMeanRatio()
    {
      set_name("I_DFT_InverseMeanRatio");
      p_set_alpha(1.0/3.0);
      p_set_beta(0.0);
      p_set_gamma(2.0/3.0);
      p_set_use_barrier_delta(false);      
   }
    
    //! virtual destructor ensures use of polymorphism during destruction
    virtual ~I_DFT_InverseMeanRatio()
       {};
  };
  
} //namespace


#endif // I_DFT__INVERSE_MEAN_RATIO_hpp
