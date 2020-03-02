#lang racket

; Largest prime factor 
; Problem 3
;
; The prime factors of 13195 are 5, 7, 13 and 29.
;
; What is the largest prime factor of the number 600851475143 ?
;
; https://projecteuler.net/problem=3

(define is-prime
  (lambda (num)
    (not (stream-ormap
          (lambda (div)
            (divides div num))
            (in-range 2 (+ (floor (sqrt num)) 1))
            )
         )
    )
  )

(define divides
  (lambda (div num) (= (modulo num div) 0))
  )

(define is-prime-divisor
  (lambda (div num) (and (divides div num) (is-prime div)))
  )

(define stream-findf
  (lambda (proc strm)
    (and (not (stream-empty? strm))
        (if (proc (stream-first strm))
            (stream-first strm)
            (stream-findf proc (stream-rest strm))
            )
        )
    )
  )

(define problem-3
  (lambda ()
    (display
     (exact-truncate
      (stream-findf
       (lambda (div) (is-prime-divisor div 600851475143))
       (in-range (+ (floor (sqrt 600851475143)) 1) 2 -1)
       )
      )
     )
    )
  )

(problem-3)
