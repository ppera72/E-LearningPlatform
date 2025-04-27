--
-- PostgreSQL database dump
--

-- Dumped from database version 17.4
-- Dumped by pg_dump version 17.4

-- Started on 2025-04-27 15:55:24

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET transaction_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- TOC entry 222 (class 1259 OID 16476)
-- Name: professordata; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.professordata (
    id_prof integer NOT NULL,
    professorname text NOT NULL,
    professorsurname text NOT NULL,
    dateofbirth date NOT NULL,
    id_major integer NOT NULL,
    id_title integer NOT NULL
);


ALTER TABLE public.professordata OWNER TO postgres;

--
-- TOC entry 221 (class 1259 OID 16468)
-- Name: professorlogindata; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.professorlogindata (
    id_prof integer NOT NULL,
    professoremail text NOT NULL,
    professorpassword text NOT NULL
);


ALTER TABLE public.professorlogindata OWNER TO postgres;

--
-- TOC entry 234 (class 1259 OID 16614)
-- Name: allprofessordata; Type: VIEW; Schema: public; Owner: postgres
--

CREATE VIEW public.allprofessordata AS
 SELECT pld.id_prof,
    pld.professoremail,
    pld.professorpassword,
    pd.professorname,
    pd.professorsurname,
    to_char((pd.dateofbirth)::timestamp with time zone, 'DD-MM-YYYY'::text) AS dateofbirth,
    pd.id_major,
    pd.id_title
   FROM (public.professorlogindata pld
     JOIN public.professordata pd ON ((pld.id_prof = pd.id_prof)));


ALTER VIEW public.allprofessordata OWNER TO postgres;

--
-- TOC entry 219 (class 1259 OID 16450)
-- Name: studentdata; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.studentdata (
    id_stud integer NOT NULL,
    studentname text NOT NULL,
    studentsurname text NOT NULL,
    dateofbirth date NOT NULL,
    id_major integer NOT NULL,
    studiesyear integer NOT NULL
);


ALTER TABLE public.studentdata OWNER TO postgres;

--
-- TOC entry 218 (class 1259 OID 16442)
-- Name: studentlogindata; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.studentlogindata (
    id_stud integer NOT NULL,
    studentemail text NOT NULL,
    studentpassword text NOT NULL
);


ALTER TABLE public.studentlogindata OWNER TO postgres;

--
-- TOC entry 233 (class 1259 OID 16610)
-- Name: allstudentdata; Type: VIEW; Schema: public; Owner: postgres
--

CREATE VIEW public.allstudentdata AS
 SELECT sld.id_stud,
    sld.studentemail,
    sld.studentpassword,
    sd.studentname,
    sd.studentsurname,
    to_char((sd.dateofbirth)::timestamp with time zone, 'DD-MM-YYYY'::text) AS dateofbirth,
    sd.id_major,
    sd.studiesyear
   FROM (public.studentlogindata sld
     JOIN public.studentdata sd ON ((sld.id_stud = sd.id_stud)));


ALTER VIEW public.allstudentdata OWNER TO postgres;

--
-- TOC entry 231 (class 1259 OID 16560)
-- Name: assignments; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.assignments (
    id_assignment integer NOT NULL,
    assignmenttitle text NOT NULL,
    assignmentdesc text,
    assignmentbegindate date NOT NULL,
    assignmentenddate date NOT NULL,
    id_major integer NOT NULL
);


ALTER TABLE public.assignments OWNER TO postgres;

--
-- TOC entry 230 (class 1259 OID 16559)
-- Name: assignments_id_assignment_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.assignments_id_assignment_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.assignments_id_assignment_seq OWNER TO postgres;

--
-- TOC entry 4921 (class 0 OID 0)
-- Dependencies: 230
-- Name: assignments_id_assignment_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.assignments_id_assignment_seq OWNED BY public.assignments.id_assignment;


--
-- TOC entry 238 (class 1259 OID 16636)
-- Name: completedassignments; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.completedassignments (
    id_ca integer NOT NULL,
    id_assignment integer NOT NULL,
    id_stud integer NOT NULL,
    filename text,
    isgraded boolean NOT NULL,
    id_major integer NOT NULL
);


ALTER TABLE public.completedassignments OWNER TO postgres;

--
-- TOC entry 237 (class 1259 OID 16635)
-- Name: completedassignments_id_ca_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.completedassignments_id_ca_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.completedassignments_id_ca_seq OWNER TO postgres;

--
-- TOC entry 4922 (class 0 OID 0)
-- Dependencies: 237
-- Name: completedassignments_id_ca_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.completedassignments_id_ca_seq OWNED BY public.completedassignments.id_ca;


--
-- TOC entry 236 (class 1259 OID 16619)
-- Name: completedtests; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.completedtests (
    id_ct integer NOT NULL,
    id_test integer NOT NULL,
    id_stud integer NOT NULL
);


ALTER TABLE public.completedtests OWNER TO postgres;

--
-- TOC entry 235 (class 1259 OID 16618)
-- Name: completedtests_id_ct_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.completedtests_id_ct_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.completedtests_id_ct_seq OWNER TO postgres;

--
-- TOC entry 4923 (class 0 OID 0)
-- Dependencies: 235
-- Name: completedtests_id_ct_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.completedtests_id_ct_seq OWNED BY public.completedtests.id_ct;


--
-- TOC entry 224 (class 1259 OID 16503)
-- Name: major; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.major (
    id_major integer NOT NULL,
    fullname text NOT NULL,
    abbreviation text NOT NULL
);


ALTER TABLE public.major OWNER TO postgres;

--
-- TOC entry 223 (class 1259 OID 16502)
-- Name: major_id_major_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.major_id_major_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.major_id_major_seq OWNER TO postgres;

--
-- TOC entry 4924 (class 0 OID 0)
-- Dependencies: 223
-- Name: major_id_major_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.major_id_major_seq OWNED BY public.major.id_major;


--
-- TOC entry 220 (class 1259 OID 16467)
-- Name: professorlogindata_id_prof_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.professorlogindata_id_prof_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.professorlogindata_id_prof_seq OWNER TO postgres;

--
-- TOC entry 4925 (class 0 OID 0)
-- Dependencies: 220
-- Name: professorlogindata_id_prof_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.professorlogindata_id_prof_seq OWNED BY public.professorlogindata.id_prof;


--
-- TOC entry 226 (class 1259 OID 16522)
-- Name: professortitle; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.professortitle (
    id_title integer NOT NULL,
    titlename text NOT NULL
);


ALTER TABLE public.professortitle OWNER TO postgres;

--
-- TOC entry 225 (class 1259 OID 16521)
-- Name: professortitle_id_title_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.professortitle_id_title_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.professortitle_id_title_seq OWNER TO postgres;

--
-- TOC entry 4926 (class 0 OID 0)
-- Dependencies: 225
-- Name: professortitle_id_title_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.professortitle_id_title_seq OWNED BY public.professortitle.id_title;


--
-- TOC entry 232 (class 1259 OID 16573)
-- Name: studentgrades; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.studentgrades (
    id_stud integer NOT NULL,
    id_prof integer NOT NULL,
    id_assignment integer,
    id_test integer,
    grade numeric(2,1) NOT NULL,
    comment text,
    CONSTRAINT studentgrades_check CHECK ((((id_assignment IS NOT NULL) AND (id_test IS NULL)) OR ((id_assignment IS NULL) AND (id_test IS NOT NULL))))
);


ALTER TABLE public.studentgrades OWNER TO postgres;

--
-- TOC entry 217 (class 1259 OID 16441)
-- Name: studentlogindata_id_stud_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.studentlogindata_id_stud_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.studentlogindata_id_stud_seq OWNER TO postgres;

--
-- TOC entry 4927 (class 0 OID 0)
-- Dependencies: 217
-- Name: studentlogindata_id_stud_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.studentlogindata_id_stud_seq OWNED BY public.studentlogindata.id_stud;


--
-- TOC entry 229 (class 1259 OID 16549)
-- Name: testquestions; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.testquestions (
    id_test integer NOT NULL,
    question text NOT NULL,
    corrans text NOT NULL,
    wroans1 text NOT NULL,
    wroans2 text NOT NULL,
    wroans3 text NOT NULL
);


ALTER TABLE public.testquestions OWNER TO postgres;

--
-- TOC entry 228 (class 1259 OID 16536)
-- Name: tests; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE public.tests (
    id_test integer NOT NULL,
    testtitle text NOT NULL,
    testbegindate date NOT NULL,
    testenddate date NOT NULL,
    id_major integer NOT NULL,
    id_prof integer NOT NULL
);


ALTER TABLE public.tests OWNER TO postgres;

--
-- TOC entry 227 (class 1259 OID 16535)
-- Name: tests_id_test_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE public.tests_id_test_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.tests_id_test_seq OWNER TO postgres;

--
-- TOC entry 4928 (class 0 OID 0)
-- Dependencies: 227
-- Name: tests_id_test_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE public.tests_id_test_seq OWNED BY public.tests.id_test;


--
-- TOC entry 4705 (class 2604 OID 16563)
-- Name: assignments id_assignment; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.assignments ALTER COLUMN id_assignment SET DEFAULT nextval('public.assignments_id_assignment_seq'::regclass);


--
-- TOC entry 4707 (class 2604 OID 16639)
-- Name: completedassignments id_ca; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.completedassignments ALTER COLUMN id_ca SET DEFAULT nextval('public.completedassignments_id_ca_seq'::regclass);


--
-- TOC entry 4706 (class 2604 OID 16622)
-- Name: completedtests id_ct; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.completedtests ALTER COLUMN id_ct SET DEFAULT nextval('public.completedtests_id_ct_seq'::regclass);


--
-- TOC entry 4702 (class 2604 OID 16506)
-- Name: major id_major; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.major ALTER COLUMN id_major SET DEFAULT nextval('public.major_id_major_seq'::regclass);


--
-- TOC entry 4701 (class 2604 OID 16471)
-- Name: professorlogindata id_prof; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.professorlogindata ALTER COLUMN id_prof SET DEFAULT nextval('public.professorlogindata_id_prof_seq'::regclass);


--
-- TOC entry 4703 (class 2604 OID 16525)
-- Name: professortitle id_title; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.professortitle ALTER COLUMN id_title SET DEFAULT nextval('public.professortitle_id_title_seq'::regclass);


--
-- TOC entry 4700 (class 2604 OID 16445)
-- Name: studentlogindata id_stud; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.studentlogindata ALTER COLUMN id_stud SET DEFAULT nextval('public.studentlogindata_id_stud_seq'::regclass);


--
-- TOC entry 4704 (class 2604 OID 16539)
-- Name: tests id_test; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.tests ALTER COLUMN id_test SET DEFAULT nextval('public.tests_id_test_seq'::regclass);


--
-- TOC entry 4910 (class 0 OID 16560)
-- Dependencies: 231
-- Data for Name: assignments; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.assignments (id_assignment, assignmenttitle, assignmentdesc, assignmentbegindate, assignmentenddate, id_major) VALUES (1, 'C++ Project Raport', 'Send raport of your current work on C++ project', '2000-01-01', '2000-01-01', 5);
INSERT INTO public.assignments (id_assignment, assignmenttitle, assignmentdesc, assignmentbegindate, assignmentenddate, id_major) VALUES (2, 'Test Assignment', 'Coś Zrób', '2025-04-27', '2025-04-28', 6);


--
-- TOC entry 4915 (class 0 OID 16636)
-- Dependencies: 238
-- Data for Name: completedassignments; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.completedassignments (id_ca, id_assignment, id_stud, filename, isgraded, id_major) VALUES (1, 1, 1, 'D:/Praca/C Plus Plus/fiel.txt', false, 5);
INSERT INTO public.completedassignments (id_ca, id_assignment, id_stud, filename, isgraded, id_major) VALUES (2, 2, 12, 'D:/Praca/C Plus Plus/fiel.txt', true, 6);


--
-- TOC entry 4913 (class 0 OID 16619)
-- Dependencies: 236
-- Data for Name: completedtests; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.completedtests (id_ct, id_test, id_stud) VALUES (1, 2, 12);


--
-- TOC entry 4903 (class 0 OID 16503)
-- Dependencies: 224
-- Data for Name: major; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.major (id_major, fullname, abbreviation) VALUES (1, 'Aviation and Astronautics', 'AvAs');
INSERT INTO public.major (id_major, fullname, abbreviation) VALUES (2, 'Chemical Engineering and Technology', 'ChET');
INSERT INTO public.major (id_major, fullname, abbreviation) VALUES (3, 'Chemical Technology', 'ChTe');
INSERT INTO public.major (id_major, fullname, abbreviation) VALUES (4, 'Civil Engineering', 'CiEn');
INSERT INTO public.major (id_major, fullname, abbreviation) VALUES (5, 'Computer Enigneering', 'CoEn');
INSERT INTO public.major (id_major, fullname, abbreviation) VALUES (6, 'Electrical Engineering', 'ElEn');
INSERT INTO public.major (id_major, fullname, abbreviation) VALUES (7, 'Finance and Accounting', 'FiAc');
INSERT INTO public.major (id_major, fullname, abbreviation) VALUES (8, 'Logistics', 'Logi');
INSERT INTO public.major (id_major, fullname, abbreviation) VALUES (9, 'Modern Management', 'MoMa');


--
-- TOC entry 4901 (class 0 OID 16476)
-- Dependencies: 222
-- Data for Name: professordata; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.professordata (id_prof, professorname, professorsurname, dateofbirth, id_major, id_title) VALUES (1, 'Patryk', 'Pera', '1986-04-06', 5, 4);
INSERT INTO public.professordata (id_prof, professorname, professorsurname, dateofbirth, id_major, id_title) VALUES (2, 'Kamil', 'Pera', '1960-01-11', 6, 3);
INSERT INTO public.professordata (id_prof, professorname, professorsurname, dateofbirth, id_major, id_title) VALUES (3, 'Piotr', 'Kowalski', '1998-01-01', 6, 4);


--
-- TOC entry 4900 (class 0 OID 16468)
-- Dependencies: 221
-- Data for Name: professorlogindata; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.professorlogindata (id_prof, professoremail, professorpassword) VALUES (1, 'you@you.pl', 'Qwerty123?');
INSERT INTO public.professorlogindata (id_prof, professoremail, professorpassword) VALUES (2, 'kamil.pera12@gmail.com', 'Qwerty123?');
INSERT INTO public.professorlogindata (id_prof, professoremail, professorpassword) VALUES (3, 'kowalski@example.com', 'Qwerty123?');


--
-- TOC entry 4905 (class 0 OID 16522)
-- Dependencies: 226
-- Data for Name: professortitle; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.professortitle (id_title, titlename) VALUES (1, 'BSc');
INSERT INTO public.professortitle (id_title, titlename) VALUES (2, 'Eng.');
INSERT INTO public.professortitle (id_title, titlename) VALUES (3, 'MSc');
INSERT INTO public.professortitle (id_title, titlename) VALUES (4, 'PhD');
INSERT INTO public.professortitle (id_title, titlename) VALUES (5, 'Prof.');


--
-- TOC entry 4898 (class 0 OID 16450)
-- Dependencies: 219
-- Data for Name: studentdata; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.studentdata (id_stud, studentname, studentsurname, dateofbirth, id_major, studiesyear) VALUES (1, 'Patryk', 'Pera', '2004-03-13', 5, 2);
INSERT INTO public.studentdata (id_stud, studentname, studentsurname, dateofbirth, id_major, studiesyear) VALUES (2, 'Jan', 'Kowalski', '1985-06-15', 5, 3);
INSERT INTO public.studentdata (id_stud, studentname, studentsurname, dateofbirth, id_major, studiesyear) VALUES (3, 'Anna', 'Nowak', '1990-09-22', 7, 5);
INSERT INTO public.studentdata (id_stud, studentname, studentsurname, dateofbirth, id_major, studiesyear) VALUES (4, 'Piotr', 'Wiśniewski', '1982-12-05', 7, 1);
INSERT INTO public.studentdata (id_stud, studentname, studentsurname, dateofbirth, id_major, studiesyear) VALUES (5, 'Maria', 'Dąbrowska', '1995-07-18', 6, 4);
INSERT INTO public.studentdata (id_stud, studentname, studentsurname, dateofbirth, id_major, studiesyear) VALUES (6, 'Tomasz', 'Lewandowski', '1988-03-30', 9, 2);
INSERT INTO public.studentdata (id_stud, studentname, studentsurname, dateofbirth, id_major, studiesyear) VALUES (7, 'Katarzyna', 'Zielińska', '1993-11-10', 3, 5);
INSERT INTO public.studentdata (id_stud, studentname, studentsurname, dateofbirth, id_major, studiesyear) VALUES (8, 'Marek', 'Szymański', '1980-03-25', 6, 3);
INSERT INTO public.studentdata (id_stud, studentname, studentsurname, dateofbirth, id_major, studiesyear) VALUES (9, 'Ewa', 'Woźniak', '1997-08-14', 1, 1);
INSERT INTO public.studentdata (id_stud, studentname, studentsurname, dateofbirth, id_major, studiesyear) VALUES (10, 'Adam', 'Kaczmarek', '1986-02-19', 5, 4);
INSERT INTO public.studentdata (id_stud, studentname, studentsurname, dateofbirth, id_major, studiesyear) VALUES (11, 'Joanna', 'Piotrowska', '1991-05-07', 5, 2);
INSERT INTO public.studentdata (id_stud, studentname, studentsurname, dateofbirth, id_major, studiesyear) VALUES (12, 'Kamil', 'Pera', '1999-01-13', 6, 2);


--
-- TOC entry 4911 (class 0 OID 16573)
-- Dependencies: 232
-- Data for Name: studentgrades; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.studentgrades (id_stud, id_prof, id_assignment, id_test, grade, comment) VALUES (12, 2, NULL, 2, 5.0, '');
INSERT INTO public.studentgrades (id_stud, id_prof, id_assignment, id_test, grade, comment) VALUES (12, 2, 2, NULL, 4.5, 'Good Job!');


--
-- TOC entry 4897 (class 0 OID 16442)
-- Dependencies: 218
-- Data for Name: studentlogindata; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.studentlogindata (id_stud, studentemail, studentpassword) VALUES (1, 'me@me.pl', 'Qwerty123?');
INSERT INTO public.studentlogindata (id_stud, studentemail, studentpassword) VALUES (2, 'jan.kowalski@example.com', 'Haslo123!');
INSERT INTO public.studentlogindata (id_stud, studentemail, studentpassword) VALUES (3, 'anna.nowak@example.com', 'Qwerty2024#');
INSERT INTO public.studentlogindata (id_stud, studentemail, studentpassword) VALUES (4, 'piotr.wisniewski@example.com', 'P@ssw0rd!');
INSERT INTO public.studentlogindata (id_stud, studentemail, studentpassword) VALUES (5, 'maria.dabrowska@example.com', 'M@ria1234');
INSERT INTO public.studentlogindata (id_stud, studentemail, studentpassword) VALUES (6, 'tomasz.lewandowski@example.com', 'Secret987*');
INSERT INTO public.studentlogindata (id_stud, studentemail, studentpassword) VALUES (7, 'katarzyna.zielinska@example.com', 'Z!elinska99');
INSERT INTO public.studentlogindata (id_stud, studentemail, studentpassword) VALUES (8, 'marek.szymanski@example.com', 'M@rekPa44');
INSERT INTO public.studentlogindata (id_stud, studentemail, studentpassword) VALUES (9, 'ewa.wozniak@example.com', 'Ew@56789');
INSERT INTO public.studentlogindata (id_stud, studentemail, studentpassword) VALUES (10, 'adam.kaczmarek@example.com', 'A!d@m123');
INSERT INTO public.studentlogindata (id_stud, studentemail, studentpassword) VALUES (11, 'joanna.piotrowska@example.com', 'J0anna!Pass');
INSERT INTO public.studentlogindata (id_stud, studentemail, studentpassword) VALUES (12, 'kamil.pera@gmail.com', 'Qwerty123?');


--
-- TOC entry 4908 (class 0 OID 16549)
-- Dependencies: 229
-- Data for Name: testquestions; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.testquestions (id_test, question, corrans, wroans1, wroans2, wroans3) VALUES (1, 'Which of the following correctly declares a constant variable in C++?', 'const int value = 10', 'int const value 10', 'constant int value = 10', 'int value const = 10');
INSERT INTO public.testquestions (id_test, question, corrans, wroans1, wroans2, wroans3) VALUES (1, 'What is the purpose of the std::vector class in C++?', 'It provides a dynamically resizable array.', 'It is a fixed-size array container.', 'It manages linked lists.', 'It sorts elements automatically.');
INSERT INTO public.testquestions (id_test, question, corrans, wroans1, wroans2, wroans3) VALUES (1, 'Which access specifier allows a member to be accessed only by derived classes in C++?', 'protected', 'public', 'private', 'friend');
INSERT INTO public.testquestions (id_test, question, corrans, wroans1, wroans2, wroans3) VALUES (1, 'What is the output of the following code? int x = 3 | x += 5 * 2 | cout << x', '13', '16', '10', '11');
INSERT INTO public.testquestions (id_test, question, corrans, wroans1, wroans2, wroans3) VALUES (1, 'Which of the following statements about C++ inheritance is true?', 'A derived class can inherit from more than one base class.', 'A derived class can only inherit from one base class.', 'C++ does not support inheritance.', 'Base classes must always be abstract.');
INSERT INTO public.testquestions (id_test, question, corrans, wroans1, wroans2, wroans3) VALUES (1, 'Which of the following declarations of a pointer to int variable is correct?', 'int* ptr', 'int ptr', '*int ptr', 'int& ptr');
INSERT INTO public.testquestions (id_test, question, corrans, wroans1, wroans2, wroans3) VALUES (2, 'Czy ten test jest świetny?', 'Tak', 'Nie', 'Nie', 'Nie');
INSERT INTO public.testquestions (id_test, question, corrans, wroans1, wroans2, wroans3) VALUES (2, 'Czy te pytania są świetne?', 'Jeszcze jak', 'nie.', 'Nie', 'Nie.');
INSERT INTO public.testquestions (id_test, question, corrans, wroans1, wroans2, wroans3) VALUES (2, 'Czy ten projekt jest świetny?', 'Tak', 'nie.', 'nie.', 'nie.');


--
-- TOC entry 4907 (class 0 OID 16536)
-- Dependencies: 228
-- Data for Name: tests; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO public.tests (id_test, testtitle, testbegindate, testenddate, id_major, id_prof) VALUES (1, 'C++ Test', '2025-04-19', '2025-04-20', 5, 1);
INSERT INTO public.tests (id_test, testtitle, testbegindate, testenddate, id_major, id_prof) VALUES (2, 'Test TEst', '2025-04-27', '2025-04-28', 6, 2);


--
-- TOC entry 4929 (class 0 OID 0)
-- Dependencies: 230
-- Name: assignments_id_assignment_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.assignments_id_assignment_seq', 2, true);


--
-- TOC entry 4930 (class 0 OID 0)
-- Dependencies: 237
-- Name: completedassignments_id_ca_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.completedassignments_id_ca_seq', 2, true);


--
-- TOC entry 4931 (class 0 OID 0)
-- Dependencies: 235
-- Name: completedtests_id_ct_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.completedtests_id_ct_seq', 1, true);


--
-- TOC entry 4932 (class 0 OID 0)
-- Dependencies: 223
-- Name: major_id_major_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.major_id_major_seq', 9, true);


--
-- TOC entry 4933 (class 0 OID 0)
-- Dependencies: 220
-- Name: professorlogindata_id_prof_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.professorlogindata_id_prof_seq', 3, true);


--
-- TOC entry 4934 (class 0 OID 0)
-- Dependencies: 225
-- Name: professortitle_id_title_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.professortitle_id_title_seq', 5, true);


--
-- TOC entry 4935 (class 0 OID 0)
-- Dependencies: 217
-- Name: studentlogindata_id_stud_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.studentlogindata_id_stud_seq', 12, true);


--
-- TOC entry 4936 (class 0 OID 0)
-- Dependencies: 227
-- Name: tests_id_test_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('public.tests_id_test_seq', 2, true);


--
-- TOC entry 4724 (class 2606 OID 16567)
-- Name: assignments assignments_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.assignments
    ADD CONSTRAINT assignments_pkey PRIMARY KEY (id_assignment);


--
-- TOC entry 4728 (class 2606 OID 16641)
-- Name: completedassignments completedassignments_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.completedassignments
    ADD CONSTRAINT completedassignments_pkey PRIMARY KEY (id_ca);


--
-- TOC entry 4726 (class 2606 OID 16624)
-- Name: completedtests completedtests_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.completedtests
    ADD CONSTRAINT completedtests_pkey PRIMARY KEY (id_ct);


--
-- TOC entry 4718 (class 2606 OID 16510)
-- Name: major major_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.major
    ADD CONSTRAINT major_pkey PRIMARY KEY (id_major);


--
-- TOC entry 4716 (class 2606 OID 16482)
-- Name: professordata professordata_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.professordata
    ADD CONSTRAINT professordata_pkey PRIMARY KEY (id_prof);


--
-- TOC entry 4714 (class 2606 OID 16475)
-- Name: professorlogindata professorlogindata_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.professorlogindata
    ADD CONSTRAINT professorlogindata_pkey PRIMARY KEY (id_prof);


--
-- TOC entry 4720 (class 2606 OID 16529)
-- Name: professortitle professortitle_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.professortitle
    ADD CONSTRAINT professortitle_pkey PRIMARY KEY (id_title);


--
-- TOC entry 4712 (class 2606 OID 16456)
-- Name: studentdata studentdata_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.studentdata
    ADD CONSTRAINT studentdata_pkey PRIMARY KEY (id_stud);


--
-- TOC entry 4710 (class 2606 OID 16449)
-- Name: studentlogindata studentlogindata_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.studentlogindata
    ADD CONSTRAINT studentlogindata_pkey PRIMARY KEY (id_stud);


--
-- TOC entry 4722 (class 2606 OID 16543)
-- Name: tests tests_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.tests
    ADD CONSTRAINT tests_pkey PRIMARY KEY (id_test);


--
-- TOC entry 4739 (class 2606 OID 16568)
-- Name: assignments fk_assignments_major; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.assignments
    ADD CONSTRAINT fk_assignments_major FOREIGN KEY (id_major) REFERENCES public.major(id_major);


--
-- TOC entry 4746 (class 2606 OID 16664)
-- Name: completedassignments fk_ca_majors; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.completedassignments
    ADD CONSTRAINT fk_ca_majors FOREIGN KEY (id_major) REFERENCES public.major(id_major);


--
-- TOC entry 4747 (class 2606 OID 16642)
-- Name: completedassignments fk_caassignment; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.completedassignments
    ADD CONSTRAINT fk_caassignment FOREIGN KEY (id_assignment) REFERENCES public.assignments(id_assignment) ON DELETE SET NULL;


--
-- TOC entry 4744 (class 2606 OID 16630)
-- Name: completedtests fk_ctstudent; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.completedtests
    ADD CONSTRAINT fk_ctstudent FOREIGN KEY (id_stud) REFERENCES public.studentdata(id_stud) ON DELETE SET NULL;


--
-- TOC entry 4748 (class 2606 OID 16647)
-- Name: completedassignments fk_ctstudent; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.completedassignments
    ADD CONSTRAINT fk_ctstudent FOREIGN KEY (id_stud) REFERENCES public.studentdata(id_stud) ON DELETE SET NULL;


--
-- TOC entry 4745 (class 2606 OID 16625)
-- Name: completedtests fk_cttest; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.completedtests
    ADD CONSTRAINT fk_cttest FOREIGN KEY (id_test) REFERENCES public.tests(id_test) ON DELETE SET NULL;


--
-- TOC entry 4736 (class 2606 OID 16659)
-- Name: tests fk_prof_tests; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.tests
    ADD CONSTRAINT fk_prof_tests FOREIGN KEY (id_prof) REFERENCES public.professordata(id_prof);


--
-- TOC entry 4733 (class 2606 OID 16516)
-- Name: professordata fk_professordata_major; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.professordata
    ADD CONSTRAINT fk_professordata_major FOREIGN KEY (id_major) REFERENCES public.major(id_major);


--
-- TOC entry 4734 (class 2606 OID 16530)
-- Name: professordata fk_professordata_professortitle; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.professordata
    ADD CONSTRAINT fk_professordata_professortitle FOREIGN KEY (id_title) REFERENCES public.professortitle(id_title);


--
-- TOC entry 4730 (class 2606 OID 16511)
-- Name: studentdata fk_studentdata_major; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.studentdata
    ADD CONSTRAINT fk_studentdata_major FOREIGN KEY (id_major) REFERENCES public.major(id_major);


--
-- TOC entry 4738 (class 2606 OID 16554)
-- Name: testquestions fk_testquestions_tests; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.testquestions
    ADD CONSTRAINT fk_testquestions_tests FOREIGN KEY (id_test) REFERENCES public.tests(id_test);


--
-- TOC entry 4737 (class 2606 OID 16544)
-- Name: tests fk_tests_major; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.tests
    ADD CONSTRAINT fk_tests_major FOREIGN KEY (id_major) REFERENCES public.major(id_major);


--
-- TOC entry 4732 (class 2606 OID 16488)
-- Name: professorlogindata fk_uq1_professorlogindata_professorlogindata; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.professorlogindata
    ADD CONSTRAINT fk_uq1_professorlogindata_professorlogindata FOREIGN KEY (id_prof) REFERENCES public.professorlogindata(id_prof) DEFERRABLE INITIALLY DEFERRED;


--
-- TOC entry 4729 (class 2606 OID 16462)
-- Name: studentlogindata fk_uq1_studentlogindata_studentlogindata; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.studentlogindata
    ADD CONSTRAINT fk_uq1_studentlogindata_studentlogindata FOREIGN KEY (id_stud) REFERENCES public.studentlogindata(id_stud) DEFERRABLE INITIALLY DEFERRED;


--
-- TOC entry 4735 (class 2606 OID 16483)
-- Name: professordata professordata_id_prof_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.professordata
    ADD CONSTRAINT professordata_id_prof_fkey FOREIGN KEY (id_prof) REFERENCES public.professorlogindata(id_prof);


--
-- TOC entry 4731 (class 2606 OID 16457)
-- Name: studentdata studentdata_id_stud_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.studentdata
    ADD CONSTRAINT studentdata_id_stud_fkey FOREIGN KEY (id_stud) REFERENCES public.studentlogindata(id_stud);


--
-- TOC entry 4740 (class 2606 OID 16587)
-- Name: studentgrades studentgrades_id_assignment_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.studentgrades
    ADD CONSTRAINT studentgrades_id_assignment_fkey FOREIGN KEY (id_assignment) REFERENCES public.assignments(id_assignment);


--
-- TOC entry 4741 (class 2606 OID 16582)
-- Name: studentgrades studentgrades_id_prof_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.studentgrades
    ADD CONSTRAINT studentgrades_id_prof_fkey FOREIGN KEY (id_prof) REFERENCES public.professorlogindata(id_prof);


--
-- TOC entry 4742 (class 2606 OID 16577)
-- Name: studentgrades studentgrades_id_stud_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.studentgrades
    ADD CONSTRAINT studentgrades_id_stud_fkey FOREIGN KEY (id_stud) REFERENCES public.studentlogindata(id_stud);


--
-- TOC entry 4743 (class 2606 OID 16592)
-- Name: studentgrades studentgrades_id_test_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY public.studentgrades
    ADD CONSTRAINT studentgrades_id_test_fkey FOREIGN KEY (id_test) REFERENCES public.tests(id_test);


-- Completed on 2025-04-27 15:55:24

--
-- PostgreSQL database dump complete
--

