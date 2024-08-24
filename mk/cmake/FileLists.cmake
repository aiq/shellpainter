
################################################################################
# SRC_FILES
################################################################################
set( SRC_FILES
)
aux_source_directory( ${SRC_DIR}/cmdscreen SRC_FILES )
aux_source_directory( ${SRC_DIR}/cmdscreen/_ SRC_FILES )
aux_source_directory( ${SRC_DIR}/cmdscreen/layout SRC_FILES )

################################################################################
# TEST_FILES
################################################################################
set( TEST_FILES
)

aux_source_directory( ${TEST_DIR}/cmdscreen TEST_FILES )
aux_source_directory( ${TEST_DIR}/cmdscreen/csLayout TEST_FILES )
aux_source_directory( ${TEST_DIR}/cmdscreen/csLimit TEST_FILES )
aux_source_directory( ${TEST_DIR}/cmdscreen/csPadding TEST_FILES )
aux_source_directory( ${TEST_DIR}/cmdscreen/csSize TEST_FILES )

################################################################################
# APP_FILES
################################################################################
set( APP_FILES
   ${APP_DIR}/cal/cal.c
   ${APP_DIR}/color-info/color-info.c
)
