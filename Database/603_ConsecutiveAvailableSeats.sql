/*
https://leetcode.com/problems/consecutive-available-seats/

Several friends at a cinema ticket office would like to reserve consecutive available seats.
Can you help to query all the consecutive available seats order by the seat_id using the following cinema table?
| seat_id | free |
|---------|------|
| 1       | 1    |
| 2       | 0    |
| 3       | 1    |
| 4       | 1    |
| 5       | 1    |
 

Your query should return the following result for the sample case above.
 

| seat_id |
|---------|
| 3       |
| 4       |
| 5       |

*/

SELECT DISTINCT cina.seat_id
FROM cinema cina JOIN cinema cinb
ON ABS(cina.seat_id - cinb.seat_id) = 1 AND cina.free = TRUE AND cinb.free = TRUE
ORDER BY cina.seat_id;