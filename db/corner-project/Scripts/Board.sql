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
VALUES(T_SEQ_BOARD.NEXTVAL, '육군 워리어 플랫폼~', '유꾼아미타이거~!!', 'army tiger', SYSDATE, SYSDATE
);

INSERT INTO T_BOARD (BNO, TITLE, CONTENT, WRITER)
(SELECT T_SEQ_BOARD.NEXTVAL, TITLE, CONTENT, WRITER FROM T_BOARD);