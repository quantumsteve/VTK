vtk_module(vtkRenderingContextOpenGL2
  TCL_NAME
    vtkRenderingContextOpenGLII
  DEPENDS
    vtkImagingCore
    vtkRenderingOpenGL2
  IMPLEMENTS
    vtkRenderingContext2D
  BACKEND
    OpenGL2
  IMPLEMENTATION_REQUIRED_BY_BACKEND
  PRIVATE_DEPENDS
    vtkRenderingFreeType
    vtkglew
  KIT
    vtkOpenGL
  )
