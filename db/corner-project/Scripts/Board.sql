-- 게시판 테이블 생성
CREATE SEQUENCE T_SEQ_BOARD;
CREATE TABLE T_BOARD (
	BNO NUMBER,
	TITLE VARCHAR(200) NOT NULL,
	CONTENT VARCHAR(3000) NOT NULL,
	WRITER VARCHAR(100) NOT NULL,
	NEWDATE DATE DEFAULT SYSDATE,
	UPDATEDATE DATE DEFAULT SYSDATE
);

ALTER TABLE T_BOARD ADD CONSTRAINT T_BOARD_PK PRIMARY KEY(BNO);

SELECT * FROM T_BOARD;

INSERT INTO T_BOARD
(BNO, TITLE, CONTENT, WRITER, NEWDATE, UPDATEDATE)
VALUES(T_SEQ_BOARD.NEXTVAL, 
'
안녕하세요 !!~
', 
'
안녕하심까!@ 잘 부탁드림다!
', 
'newbie'
,SYSDATE, SYSDATE);

INSERT INTO T_BOARD (BNO, TITLE, CONTENT, WRITER)
(SELECT T_SEQ_BOARD.NEXTVAL, TITLE, CONTENT, WRITER FROM T_BOARD);

----------
-- 댓글 테이블 추가
CREATE SEQUENCE SEQ_REPLY;
CREATE TABLE TBL_REPLY(
	RNO NUMBER(10),
	BNO NUMBER(10) NOT NULL,
	REPLY VARCHAR2(1000) NOT NULL, -- 댓글 
	REPLYER VARCHAR2(100) NOT NULL, -- 작성자
	REPLYDATE DATE DEFAULT SYSDATE, -- 작성날짜 
	UPDATEDATE DATE DEFAULT SYSDATE -- 수정날짜
);

ALTER TABLE TBL_REPLY ADD CONSTRAINT PK_REPLY PRIMARY KEY(RNO);
-- ALTER TABLE TBL_REPLY DROP CONSTRAINT FK_REPLY;

ALTER TABLE TBL_REPLY ADD CONSTRAINT FK_REPLY FOREIGN KEY(BNO)
REFERENCES T_BOARD(BNO) ON DELETE CASCADE;

SELECT * FROM TBL_REPLY;

INSERT INTO TBL_REPLY (RNO, BNO, REPLY, REPLYER) VALUES (SEQ_REPLY.NEXTVAL, 1, '너무 좋은데용?!', '프로댓글러');


-----------------------------------
-- 멤버 테이블 추가
CREATE TABLE TBL_MEMBER (
	USERNAME VARCHAR2(40) NOT NULL,
	PASSWORD VARCHAR2(100) NOT NULL,
	EMAILADDRESS VARCHAR2(100) NOT NULL,
	REGDATE DATE DEFAULT SYSDATE,
	PRIMARY KEY(USERNAME)
);

SELECT * FROM TBL_MEMBER;