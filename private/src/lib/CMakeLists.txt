project(calc)

aux_source_directory(../. HW_SRC_FILES)

add_library(${PROJECT_NAME} STATIC ${HW_SRC_FILES})