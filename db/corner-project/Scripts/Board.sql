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
VALUES(T_SEQ_BOARD.NEXTVAL, '멸공의 횃불', '1절
아름다운 이 강산을 지키는 우리
사나이 기백으로 오늘을 산다
포탄의 불바다를 무릅쓰면서[2]
고향 땅 부모형제 평화를 위해
2절
조국의 푸른 바다 지키는 우리
젊음의 정열바쳐 오늘을 산다
함포의 벼락불을 쏘아붙이며
겨레의 생명선에 내일을 걸고
3절
자유의 푸른 하늘 지키는 우리
충정과 투지로서 오늘을 산다
번갯불 은빛 날개 구름을 뚫고
찬란한 사명감에 날개를 편다
4절
조국의 빛난 얼을 지키는 우리
자랑과 보람으로 오늘을 산다
새 역사 창조하는 번영의 이 땅
지키고 싸워 이겨 잘 살아가자
후렴
전우여 내 나라는 내가 지킨다
멸공의 횃불 아래 목숨을 건다', '군가', SYSDATE, SYSDATE
);

INSERT INTO T_BOARD (BNO, TITLE, CONTENT, WRITER)
(SELECT T_SEQ_BOARD.NEXTVAL, TITLE, CONTENT, WRITER FROM T_BOARD);