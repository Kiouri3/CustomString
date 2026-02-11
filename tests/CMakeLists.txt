# Скачиваем Catch2
include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.5.0
)
FetchContent_MakeAvailable(Catch2)

# Исполняемый файл тестов
add_executable(string_tests 
    string_public_test.cpp
)

# Линкуем с библиотекой
target_link_libraries(string_tests
    PRIVATE
        cppstring
        Catch2::Catch2WithMain
)

add_test(NAME StringTests COMMAND string_tests)