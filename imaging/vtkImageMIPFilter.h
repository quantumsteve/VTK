/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkImageMIPFilter.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$
  Thanks:    Thanks to Abdalmajeid M. Alyassin who developed this class.

Copyright (c) 1993-1995 Ken Martin, Will Schroeder, Bill Lorensen.

This software is copyrighted by Ken Martin, Will Schroeder and Bill Lorensen.
The following terms apply to all files associated with the software unless
explicitly disclaimed in individual files. This copyright specifically does
not apply to the related textbook "The Visualization Toolkit" ISBN
013199837-4 published by Prentice Hall which is covered by its own copyright.

The authors hereby grant permission to use, copy, and distribute this
software and its documentation for any purpose, provided that existing
copyright notices are retained in all copies and that this notice is included
verbatim in any distributions. Additionally, the authors grant permission to
modify this software and its documentation for any purpose, provided that
such modifications are not distributed without the explicit consent of the
authors and that existing copyright notices are retained in all copies. Some
of the algorithms implemented by this software are patented, observe all
applicable patent law.

IN NO EVENT SHALL THE AUTHORS OR DISTRIBUTORS BE LIABLE TO ANY PARTY FOR
DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
OF THE USE OF THIS SOFTWARE, ITS DOCUMENTATION, OR ANY DERIVATIVES THEREOF,
EVEN IF THE AUTHORS HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

THE AUTHORS AND DISTRIBUTORS SPECIFICALLY DISCLAIM ANY WARRANTIES, INCLUDING,
BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
PARTICULAR PURPOSE, AND NON-INFRINGEMENT.  THIS SOFTWARE IS PROVIDED ON AN
"AS IS" BASIS, AND THE AUTHORS AND DISTRIBUTORS HAVE NO OBLIGATION TO PROVIDE
MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.


=========================================================================*/
// .NAME vtkImageMIPFilter - Maximum Intensity Projections of pixel values
// .SECTION Description
// vtkImageMIPFilter is a filter that takes the maximum or minimum intensity 
// projections along any orthogonal plane (x-y, x-z, or y-z).


#ifndef __vtkImageMIPFilter_h
#define __vtkImageMIPFilter_h


#include "vtkImageFilter.h"

class VTK_EXPORT vtkImageMIPFilter : public vtkImageFilter
{
public:
  vtkImageMIPFilter();
  char *GetClassName() {return "vtkImageMIPFilter";};
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Set/Get the range of slices for MIPs
     vtkSetVector2Macro(ProjectionRange,int);
     vtkGetVector2Macro(ProjectionRange,int);

  // Description:
  // Set/Get Min Intensity Projection = 0 or Max Intensity Projection = 1
     vtkSetMacro(MinMaxIP,int);
     vtkGetMacro(MinMaxIP,int);

  // Description:
  // Select MIP parallel to x-y plane.
  vtkSetMacro(MIPZ,int);
  vtkGetMacro(MIPZ,int);
  vtkBooleanMacro(MIPZ,int);

  // Description:
  // Select MIP parallel to x-z plane.
  vtkSetMacro(MIPY,int);
  vtkGetMacro(MIPY,int);
  vtkBooleanMacro(MIPY,int);

  // Description:
  // Select MIP parallel to y-z plane.
  vtkSetMacro(MIPX,int);
  vtkGetMacro(MIPX,int);
  vtkBooleanMacro(MIPX,int);

protected:
  int ProjectionRange[2];
  int MinMaxIP;
  int MIPX;
  int MIPY;
  int MIPZ;

  void ComputeOutputImageInformation(vtkImageRegion *inRegion,
				     vtkImageRegion *outRegion);
  void ComputeRequiredInputRegionExtent(vtkImageRegion *outRegion, 
				   vtkImageRegion *inRegion);
  void Execute(vtkImageRegion *inRegion, vtkImageRegion *outRegion);
};

#endif



