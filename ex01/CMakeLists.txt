# CMakeList.txt: progetto CMake per CPP42. Includere l'origine e definire
# qui la logica specifica del progetto.
#

# Aggiungere l'origine all'eseguibile di questo progetto.
add_executable (CPP42 "main.cpp" "Bureaucrat.cpp" "Bureaucrat.hpp" "Form.cpp" "Form.hpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CPP42 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Aggiungere i test e, se necessario, installare le destinazioni.
