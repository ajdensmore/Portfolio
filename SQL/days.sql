/*
:x

*/
select q2.submission_date, q2.Visitors, h.hacker_id, h.name from
(select d.submission_date, q1.Visitors, d.hacker_id from
(SELECT TOP 2147483647 wks.submission_date, COUNT(hacker_id) as Visitors
FROM (SELECT TOP 2147483647 a.hacker_id, MIN(a.submission_date) AS FinalVisit
      FROM Submissions a 
           INNER JOIN Submissions Firstsubmission_date
           ON a.hacker_id = Firstsubmission_date.hacker_id
      WHERE a.submission_date >= '2016-03-01'
        AND Firstsubmission_date.submission_date = '2016-03-01'
        AND NOT EXISTS (SELECT 1 
                        FROM Submissions b
                        WHERE b.submission_date = dateadd(day, 1, a.submission_date)
                          AND b.hacker_id = a.hacker_id)
      GROUP BY a.hacker_id) fv
     INNER JOIN
     (SELECT DISTINCT submission_date 
      FROM Submissions
      WHERE submission_date >= '2016-03-01') wks
     ON fv.FinalVisit >= wks.submission_date 
GROUP BY wks.submission_date
ORDER BY wks.submission_date) q1
inner join (select c.submission_date, c.hacker_id
from
  (
    select TOP 2147483647 submission_date, hacker_id, count(hacker_id) as cnt, 
    row_number() over(partition by submission_date order by submission_date, count(hacker_id) desc, hacker_id) as rn 
    from Submissions
    group by submission_date, hacker_id
  ) c
where c.rn = 1) d
on q1.submission_date = d.submission_date) q2
inner join Hackers h
on h.hacker_id = q2.hacker_id;
