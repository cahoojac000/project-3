cmake_minimum_required(VERSION 3.21)
project(project_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(project_3
        AddAutomaton.cpp
        AddAutomaton.h
        Automaton.h
        ColonAutomaton.cpp
        ColonAutomaton.h
        ColonDashAutomaton.cpp
        ColonDashAutomaton.h
        CommaAutomaton.cpp
        CommaAutomaton.h
        CommentAutomaton.cpp
        CommentAutomaton.h
        FactsAutomaton.cpp
        FactsAutomaton.h
        IdAutomaton.cpp
        IdAutomaton.h
        LeftParenAutomaton.cpp
        LeftParenAutomaton.h
        Lexer.cpp
        Lexer.h
        main.cpp
        MultiplyAutomaton.cpp
        MultiplyAutomaton.h
        PeriodAutomaton.cpp
        PeriodAutomaton.h
        QueriesAutomaton.cpp
        QueriesAutomaton.h
        QuestionMarkAutomaton.cpp
        QuestionMarkAutomaton.h
        RightParenAutomaton.cpp
        RightParenAutomaton.h
        RulesAutomaton.cpp
        RulesAutomaton.h
        SchemesAutomaton.cpp
        SchemesAutomaton.h
        StringAutomaton.cpp
        StringAutomaton.h
        Token.cpp
        Token.h Parser.cpp Parser.h DatalogProgram.h Predicate.cpp Predicate.h Rule.cpp Rule.h Parameter.cpp Parameter.h DatalogProgam.cpp)
