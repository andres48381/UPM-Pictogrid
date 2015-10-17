PROJECT(PICTOGRID)

ADD_LIBRARY(common			Casilla.cpp
					Fondo.cpp
					OpenGL.cpp
					Panel.cpp
					Panel_Flechas.cpp
					Panel_Interaccion.cpp
					Panel_Juego.cpp				
					Panel_Solucion.cpp
					Socket.cpp	
					)
ADD_EXECUTABLE(server servidor.cpp EscenarioServidor.cpp)
ADD_EXECUTABLE(client cliente.cpp EscenarioCliente.cpp)				


TARGET_LINK_LIBRARIES(server common glut GLU GL pthread)
TARGET_LINK_LIBRARIES(client common glut GLU GL pthread)
					

					
