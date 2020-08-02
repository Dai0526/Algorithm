/*
Write an SQL query to find the average selling price for each product.

average_price should be rounded to 2 decimal places.

The query result format is in the following example:

Prices table:
+------------+------------+------------+--------+
| product_id | start_date | end_date   | price  |
+------------+------------+------------+--------+
| 1          | 2019-02-17 | 2019-02-28 | 5      |
| 1          | 2019-03-01 | 2019-03-22 | 20     |
| 2          | 2019-02-01 | 2019-02-20 | 15     |
| 2          | 2019-02-21 | 2019-03-31 | 30     |
+------------+------------+------------+--------+
 
UnitsSold table:
+------------+---------------+-------+
| product_id | purchase_date | units |
+------------+---------------+-------+
| 1          | 2019-02-25    | 100   |
| 1          | 2019-03-01    | 15    |
| 2          | 2019-02-10    | 200   |
| 2          | 2019-03-22    | 30    |
+------------+---------------+-------+

Result table:
+------------+---------------+
| product_id | average_price |
+------------+---------------+
| 1          | 6.96          |
| 2          | 16.96         |
+------------+---------------+
Average selling price = Total Price of Product / Number of products sold.
Average selling price for product 1 = ((100 * 5) + (15 * 20)) / 115 = 6.96
Average selling price for product 2 = ((200 * 15) + (30 * 30)) / 230 = 16.96

https://leetcode.com/problems/average-selling-price/
*/

/*
// Not a clean solution
SELECT profit.product_id, ROUND(profit.totalPrice/sales.totalUnit, 2) AS average_price 

FROM (SELECT u.product_id, SUM((u.units * p.price)) AS totalPrice
    FROM Prices p JOIN UnitsSold u
    ON p.product_id = u.product_id
    WHERE u.purchase_date >= p.start_date AND u.purchase_date <= p.end_date
    GROUP BY u.product_id) AS profit

JOIN (SELECT product_id, SUM(units) AS totalUnit
        FROM UnitsSold
        GROUP BY product_id) AS sales
ON profit.product_id = sales.product_id;
*/

SELECT p.product_id, ROUND(SUM(u.units * p.price) / SUM(u.units), 2) as average_price
FROM Prices as p
JOIN UnitsSold as u
ON p.product_id = u.product_id AND (u.purchase_date BETWEEN p.start_date AND p.end_date)
GROUP BY p.product_id;