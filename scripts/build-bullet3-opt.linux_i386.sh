cmake -S "../thirdparty/bullet3_fork" -B "../thirdparty/build/bullet3/opt.linux_i386" -DCMAKE_INSTALL_PREFIX="../thirdparty/install/bullet3/opt.linux_i386" -DCMAKE_BUILD_TYPE=Release  -DCMAKE_CXX_FLAGS=-m32 -DCMAKE_C_FLAGS=-m32 -DBUILD_SHARED_LIBS=FALSE -DUSE_GLUT=FALSE -DUSE_GRAPHICAL_BENCHMARK=FALSE -DBUILD_BULLET2_DEMOS=FALSE -DBUILD_BULLET_ROBOTICS_EXTRA=FALSE -DBUILD_BULLET_ROBOTICS_GUI_EXTRA=FALSE  -DBUILD_BULLET_EXTRAS=FALSE -DBUILD_CLSOCKET=FALSE -DBUILD_EXTRAS=FALSE -DBUILD_CPU_DEMOS=FALSE -DBUILD_EGL=FALSE -DBUILD_GIMPACTUTILS_EXTRA=FALSE -DBUILD_HACD_EXTRA=FALSE -DBUILD_INVERSE_DYNAMIC_EXTRA=FALSE -DBUILD_OBJ2SDF=FALSE -DBUILD_OBJ2SDF_EXTRA=FALSE -DBUILD_SERIALIZE_EXTRA=FALSE -DBUILD_ENET=FALSE -DBUILD_OPENGL3_DEMOS=FALSE -DBUILD_UNIT_TESTS=FALSE -DENABLE_VHACD=FALSE -DINSTALL_EXTRA_LIBS=FALSE -DINSTALL_CMAKE_FILES=FALSE -DUSE_SOFT_BODY_MULTI_BODY_DYNAMICS_WORLD=FALSE -DCONVEX_DECOMPOSITION_EXTRA=FALSE -DINSTALL_LIBS=TRUE -DLINK_AGAINST_OLDER_GLIBC=TRUE -DOLDER_GLIBC_PATH="${CMAKE_SOURCE_DIR}../../../glibc_224/force_link_glibc_2.24.h"

cmake --build "../thirdparty/build/bullet3/opt.linux_i386" --target install