list(APPEND KenKenGameLibSources 
"BoxConstraint.cpp"
"KenKenBoard.cpp"
"KenKenGameManager.cpp"
)

add_library(KenKenGameLib ${KenKenGameLibSources})
target_include_directories(KenKenGameLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})