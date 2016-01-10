DROP TABLE IF EXISTS test_ways;
DROP TABLE IF EXISTS test_ways_vertices;
SELECT * INTO test_ways from ways;
SELECT * INTO test_ways_vertices from ways_vertices_pgr;
alter table test_ways_vertices alter column lon type numeric(20,10);
alter table test_ways_vertices alter column lat type numeric(20,10);
alter table test_ways alter column x1 type numeric(20,10);
alter table test_ways alter column y1 type numeric(20,10);
alter table test_ways alter column x2 type numeric(20,10);
alter table test_ways alter column y2 type numeric(20,10);
SELECT UpdateGeometrySRID('test_ways_vertices','the_geom',2030);
 update test_ways_vertices set the_geom=ST_Transform(ST_SetSrid(the_geom,4326),2030);
 update test_ways_vertices set lon=ST_X(the_geom),lat=ST_Y(the_geom);
SELECT UpdateGeometrySRID('test_ways','the_geom',2030);
update test_ways set the_geom=ST_Transform(ST_SetSrid(the_geom,4326),2030);
update test_ways 
	set x1=ST_X(ST_StartPoint(the_geom)),y1=ST_Y(ST_StartPoint(the_geom)),
	x2=ST_X(ST_EndPoint(the_geom)),y2=ST_Y(ST_EndPoint(the_geom));
