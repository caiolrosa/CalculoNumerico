SUBROUTINE get_ranking(matrix, ranking, statusCode)
	INTEGER :: statusCode, matrixSize, i
	DOUBLE PRECISION :: matrixSizeDBL, threshold, temp
	DOUBLE PRECISION, DIMENSION(:,:) :: matrix
	DOUBLE PRECISION, DIMENSION(:,:) :: ranking
	DOUBLE PRECISION, DIMENSION(:,:), ALLOCATABLE :: S
	
	statusCode = 123
	threshold = 1E-5

	! Verifica se a matriz é quadrada
	matrixSizeDBL = SQRT(REAL(SIZE(matrix)))
	matrixSize = INT(matrixSizeDBL)
	IF ((matrixSizeDBL * matrixSizeDBL) /= (INT(matrixSizeDBL) * INT(matrixSizeDBL))) THEN
		statusCode = 1
		STOP 1
	END IF 

	allocate (S(matrixSize, 1))
	
	do i = 1, matrixSize
		S(i,1) = (1.0 / matrixSize) 
		ranking(i,1) = 1.0 / matrixSize
	end do
	
	temp = 1
	do while (ABS(temp -  ranking(1,1)) > threshold)
		temp = ranking(1,1)
		matrix = matmul(matrix, matrix)
	    ranking = matmul(matrix, S)
	end do

	do i=1, matrixSize
		PRINT *, ranking(i, 1)
	end do
	
	deallocate(S)
END SUBROUTINE