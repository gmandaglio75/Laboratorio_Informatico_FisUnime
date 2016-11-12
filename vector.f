c G. Mandaglio oct 17 2016
c simple program twin with a c++ version
      Program vector
      integer indice,i,vettor(100)
     

      print*,"dammi un numero\n"
      read*,indice

c      integer vettor(indice)

      do i=0,indice
      vettor(i) = i+1
      enddo

      do i=0, indice
       print*,vettor(i)
      enddo

      return
      end
