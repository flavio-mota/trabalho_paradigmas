(defun rainhas (n &optional (m n)) ;pode receber um parametro m opcional
  (if (zerop n) ;verifica se n=0
      (list nil) ; retorna uma lista vazia
      (loop for solucao in (rainhas (1- n) m) ;itera entre as soluções geradas
            nconc (loop for nova-coluna from 1 to m ;concatena as listas da iteração das colunas da solução
                         when (loop for linha from 1 to n 
                                     for coluna in solucao
                                     always (/= nova-coluna coluna (+ coluna linha) (- coluna linha))) ;testa as condições de ataque
                         collect (cons nova-coluna solucao))))); faz o retorno das soluções onde não há situação de ataque
 
 ;;função para imprimir as soluções
(defun imprime-solucao (solucao)
  (loop for r-coluna in solucao
        do (loop for coluna from 1 to (length solucao)
                  do (write-char (if (= coluna r-coluna) #\Q #\.)))
           (terpri))
  (terpri))
 
(defun imprime-rainhas (n)
  (mapc #'imprime-solucao (rainhas n)))