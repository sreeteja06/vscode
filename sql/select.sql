SELECT *  --to select all the col
--casting
SELECT cast(productID AS VARCHAR(5))+':'+name AS productname
FROM product.imformation;

SELECT name,TRY_CAST (size AS INTEGER) AS numericsize
FROM saleslt.product

SELECT SalesOrderID + ' (' + STR(RevisionNumber, 1) + ')' AS OrderRevision,
	   CONVERT(NVARCHAR(30), OrderDate, 102) AS OrderDate
FROM SalesLT.SalesOrderHeader;
-- working with nulls
select productnumber ,ISNULL(color,'')+','+ISNULL(size,'') AS productdetails
FROM saleslt.product                           --returns value of colur as string if it is not null same goes to size

SELECT name, ISNULL(TRY_CAST(size AS INTEGER),0)as numericsize   --returns 0 if trycast fails because v have a zero
FROM saleslt.product

SELECT name, NULLIF(color, 'MULTI') AS singlecolor
FROM saleslt.product                           --make the color null if the value is multi

SELECT name, COALESCE(Discontinueddate, sellendDate, sellstartdate) AS lastactivity
FROM saleslt.product

SELECT name,
        CASE
            WHEN sellendDate IS NULL THEN 'on sale'
            ELSE 'discontinued'
        END AS SalesStatus
FROM saleslt.product

SELECT DISTINCT ISNULL(Color, 'NONE')AS color
FROM saleslt.product        --for removing duplicates

SELECT ProductCategory AS category,productname
FROM saleslt.product
ORDER BY Category, price DESC; --USING order by to sort the results and desc means descending

SELECT TOP 10 category
FROM saleslt.product
ORDER BY Category;   --to display the top 10 elements

SELECT name, listprice
FROM saleslt.product
ORDER BY productnumber 
OFFSET 0 ROWS
FETCH NEXT 10 ROWS ONLY;        --offset and fetch are used to display the next 10 items

--WHERE (=<>,in,between,like,and,or,not)
SELECT name,listprice
FROM salesit.product
WHERE listprice=1000;

SELECT name,listprice
FROM salesit.product
WHERE name like '%fr' --will display the name starting with fr

SELECT name,listprice
FROM salesit.product
WHERE name like 'fr%' --will display the name ending with fr

SELECT name,listprice
FROM salesit.product
WHERE name like '%fr%' --will display the name with has fr with it

SELECT name,productid
FROM salesit.product
where productid like 'fr-_[0-9][0-9]_-[0-9]' --where underscore is a litteral dash there can be any letter

SELECT name,listprice
FROM salesit.product
WHERE listprice in (3,4,5)  --if list price is equal yo 3 or 4 or 5
WHERE listprice in (3,4,5)  --if list price is equal yo 3 or 4 or 5

--to match characters that are not R, use [^R]
--JOINS (INNER, OUTER, )
--(again outer has right left and full)
SELECT emp.firstname, ord.amount --USING JOIN
FROM HR.employee AS emp 
INNER JOIN Sales.SalesOrder AS ord
on emp.Employeeid=ord.employeeid


SELECT sh.name     --using multiple join
FROM saleslt.header AS Sh
JOIN saleslt.customer AS sc
ON sc.id=Sh.id
JOIN salesit.product AS Sp
ON Sp.productid=sh.id

SELECT emp.FirstName, prd.name
FROM HR.Employee AS emp
CROSS JOIN production.product AS prod;

SELECT FirstName, LastName, 'employee' AS Type1  -- using union(selecting multiple rows)
FROM Saleslt.employee
UNION                       -- use union all to avoid distinct
SELECT FirstName, LastName, 'customer' AS Type2
FROM Saleslt.customer
ORDER BY LastName;

SELECT FirstName, LastName  -- using intersect(selecting only the common rows)
FROM Saleslt.employee
INTERSECT
SELECT FirstName, LastName
FROM Saleslt.customer
ORDER BY LastName;

SELECT FirstName, LastName  -- using except(selecting only the rows from the first table and not in the second table)
FROM Saleslt.employee
INTERSECT
SELECT FirstName, LastName
FROM Saleslt.customer
ORDER BY LastName;

