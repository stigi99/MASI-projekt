include(/Users/mateuszmisiak/nienazwane3/build/Qt_6_8_2_for_macOS-Debug/.qt/QtDeploySupport.cmake)
include("${CMAKE_CURRENT_LIST_DIR}/nienazwane3-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE nienazwane3.app
)
