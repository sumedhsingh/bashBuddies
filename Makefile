all: main  # 'all' is a meta-target that depends on 'main'

main:      # 'main' is the target to build the main executable
    g++ src/main.cpp -o bin/utility_tool  # Compile 'main.cpp' into 'utility_tool'
