/*

Create a function to generate all string character permutations.

Examples

permutations("AB") ➞ "AB BA"

permutations("CD") ➞ "CD DC"

permutations("EF") ➞ "EF FE"

permutations("NOT") ➞ "NOT NTO ONT OTN TNO TON"

permutations("RAM") ➞ "AMR ARM MAR MRA RAM RMA"

permutations("YAW") ➞ "AWY AYW WAY WYA YAW YWA"

Notes

Sort your results in alphabetical order before returning them.

*/

package main

import (
	"sort"
	"strings"
)

func main() {
	assert(permutations("AB") == "AB BA")
	assert(permutations("CD") == "CD DC")
	assert(permutations("EF") == "EF FE")
	assert(permutations("NOT") == "NOT NTO ONT OTN TNO TON")
	assert(permutations("RAM") == "AMR ARM MAR MRA RAM RMA")
	assert(permutations("YAW") == "AWY AYW WAY WYA YAW YWA")
	assert(permutations("FELT") == "EFLT EFTL ELFT ELTF ETFL ETLF FELT FETL FLET FLTE FTEL FTLE LEFT LETF LFET LFTE LTEF LTFE TEFL TELF TFEL TFLE TLEF TLFE")
	assert(permutations("LURE") == "ELRU ELUR ERLU ERUL EULR EURL LERU LEUR LREU LRUE LUER LURE RELU REUL RLEU RLUE RUEL RULE UELR UERL ULER ULRE UREL URLE")
	assert(permutations("ROME") == "EMOR EMRO EOMR EORM ERMO EROM MEOR MERO MOER MORE MREO MROE OEMR OERM OMER OMRE OREM ORME REMO REOM RMEO RMOE ROEM ROME")
	assert(permutations("COAST") == "ACOST ACOTS ACSOT ACSTO ACTOS ACTSO AOCST AOCTS AOSCT AOSTC AOTCS AOTSC ASCOT ASCTO ASOCT ASOTC ASTCO ASTOC ATCOS ATCSO ATOCS ATOSC ATSCO ATSOC CAOST CAOTS CASOT CASTO CATOS CATSO COAST COATS COSAT COSTA COTAS COTSA CSAOT CSATO CSOAT CSOTA CSTAO CSTOA CTAOS CTASO CTOAS CTOSA CTSAO CTSOA OACST OACTS OASCT OASTC OATCS OATSC OCAST OCATS OCSAT OCSTA OCTAS OCTSA OSACT OSATC OSCAT OSCTA OSTAC OSTCA OTACS OTASC OTCAS OTCSA OTSAC OTSCA SACOT SACTO SAOCT SAOTC SATCO SATOC SCAOT SCATO SCOAT SCOTA SCTAO SCTOA SOACT SOATC SOCAT SOCTA SOTAC SOTCA STACO STAOC STCAO STCOA STOAC STOCA TACOS TACSO TAOCS TAOSC TASCO TASOC TCAOS TCASO TCOAS TCOSA TCSAO TCSOA TOACS TOASC TOCAS TOCSA TOSAC TOSCA TSACO TSAOC TSCAO TSCOA TSOAC TSOCA")
	assert(permutations("SKATE") == "AEKST AEKTS AESKT AESTK AETKS AETSK AKEST AKETS AKSET AKSTE AKTES AKTSE ASEKT ASETK ASKET ASKTE ASTEK ASTKE ATEKS ATESK ATKES ATKSE ATSEK ATSKE EAKST EAKTS EASKT EASTK EATKS EATSK EKAST EKATS EKSAT EKSTA EKTAS EKTSA ESAKT ESATK ESKAT ESKTA ESTAK ESTKA ETAKS ETASK ETKAS ETKSA ETSAK ETSKA KAEST KAETS KASET KASTE KATES KATSE KEAST KEATS KESAT KESTA KETAS KETSA KSAET KSATE KSEAT KSETA KSTAE KSTEA KTAES KTASE KTEAS KTESA KTSAE KTSEA SAEKT SAETK SAKET SAKTE SATEK SATKE SEAKT SEATK SEKAT SEKTA SETAK SETKA SKAET SKATE SKEAT SKETA SKTAE SKTEA STAEK STAKE STEAK STEKA STKAE STKEA TAEKS TAESK TAKES TAKSE TASEK TASKE TEAKS TEASK TEKAS TEKSA TESAK TESKA TKAES TKASE TKEAS TKESA TKSAE TKSEA TSAEK TSAKE TSEAK TSEKA TSKAE TSKEA")
	assert(permutations("RITES") == "EIRST EIRTS EISRT EISTR EITRS EITSR ERIST ERITS ERSIT ERSTI ERTIS ERTSI ESIRT ESITR ESRIT ESRTI ESTIR ESTRI ETIRS ETISR ETRIS ETRSI ETSIR ETSRI IERST IERTS IESRT IESTR IETRS IETSR IREST IRETS IRSET IRSTE IRTES IRTSE ISERT ISETR ISRET ISRTE ISTER ISTRE ITERS ITESR ITRES ITRSE ITSER ITSRE REIST REITS RESIT RESTI RETIS RETSI RIEST RIETS RISET RISTE RITES RITSE RSEIT RSETI RSIET RSITE RSTEI RSTIE RTEIS RTESI RTIES RTISE RTSEI RTSIE SEIRT SEITR SERIT SERTI SETIR SETRI SIERT SIETR SIRET SIRTE SITER SITRE SREIT SRETI SRIET SRITE SRTEI SRTIE STEIR STERI STIER STIRE STREI STRIE TEIRS TEISR TERIS TERSI TESIR TESRI TIERS TIESR TIRES TIRSE TISER TISRE TREIS TRESI TRIES TRISE TRSEI TRSIE TSEIR TSERI TSIER TSIRE TSREI TSRIE")
	assert(permutations("POOLED") == "DELOOP DELOOP DELOPO DELOPO DELPOO DELPOO DEOLOP DEOLOP DEOLPO DEOLPO DEOOLP DEOOLP DEOOPL DEOOPL DEOPLO DEOPLO DEOPOL DEOPOL DEPLOO DEPLOO DEPOLO DEPOLO DEPOOL DEPOOL DLEOOP DLEOOP DLEOPO DLEOPO DLEPOO DLEPOO DLOEOP DLOEOP DLOEPO DLOEPO DLOOEP DLOOEP DLOOPE DLOOPE DLOPEO DLOPEO DLOPOE DLOPOE DLPEOO DLPEOO DLPOEO DLPOEO DLPOOE DLPOOE DOELOP DOELOP DOELPO DOELPO DOEOLP DOEOLP DOEOPL DOEOPL DOEPLO DOEPLO DOEPOL DOEPOL DOLEOP DOLEOP DOLEPO DOLEPO DOLOEP DOLOEP DOLOPE DOLOPE DOLPEO DOLPEO DOLPOE DOLPOE DOOELP DOOELP DOOEPL DOOEPL DOOLEP DOOLEP DOOLPE DOOLPE DOOPEL DOOPEL DOOPLE DOOPLE DOPELO DOPELO DOPEOL DOPEOL DOPLEO DOPLEO DOPLOE DOPLOE DOPOEL DOPOEL DOPOLE DOPOLE DPELOO DPELOO DPEOLO DPEOLO DPEOOL DPEOOL DPLEOO DPLEOO DPLOEO DPLOEO DPLOOE DPLOOE DPOELO DPOELO DPOEOL DPOEOL DPOLEO DPOLEO DPOLOE DPOLOE DPOOEL DPOOEL DPOOLE DPOOLE EDLOOP EDLOOP EDLOPO EDLOPO EDLPOO EDLPOO EDOLOP EDOLOP EDOLPO EDOLPO EDOOLP EDOOLP EDOOPL EDOOPL EDOPLO EDOPLO EDOPOL EDOPOL EDPLOO EDPLOO EDPOLO EDPOLO EDPOOL EDPOOL ELDOOP ELDOOP ELDOPO ELDOPO ELDPOO ELDPOO ELODOP ELODOP ELODPO ELODPO ELOODP ELOODP ELOOPD ELOOPD ELOPDO ELOPDO ELOPOD ELOPOD ELPDOO ELPDOO ELPODO ELPODO ELPOOD ELPOOD EODLOP EODLOP EODLPO EODLPO EODOLP EODOLP EODOPL EODOPL EODPLO EODPLO EODPOL EODPOL EOLDOP EOLDOP EOLDPO EOLDPO EOLODP EOLODP EOLOPD EOLOPD EOLPDO EOLPDO EOLPOD EOLPOD EOODLP EOODLP EOODPL EOODPL EOOLDP EOOLDP EOOLPD EOOLPD EOOPDL EOOPDL EOOPLD EOOPLD EOPDLO EOPDLO EOPDOL EOPDOL EOPLDO EOPLDO EOPLOD EOPLOD EOPODL EOPODL EOPOLD EOPOLD EPDLOO EPDLOO EPDOLO EPDOLO EPDOOL EPDOOL EPLDOO EPLDOO EPLODO EPLODO EPLOOD EPLOOD EPODLO EPODLO EPODOL EPODOL EPOLDO EPOLDO EPOLOD EPOLOD EPOODL EPOODL EPOOLD EPOOLD LDEOOP LDEOOP LDEOPO LDEOPO LDEPOO LDEPOO LDOEOP LDOEOP LDOEPO LDOEPO LDOOEP LDOOEP LDOOPE LDOOPE LDOPEO LDOPEO LDOPOE LDOPOE LDPEOO LDPEOO LDPOEO LDPOEO LDPOOE LDPOOE LEDOOP LEDOOP LEDOPO LEDOPO LEDPOO LEDPOO LEODOP LEODOP LEODPO LEODPO LEOODP LEOODP LEOOPD LEOOPD LEOPDO LEOPDO LEOPOD LEOPOD LEPDOO LEPDOO LEPODO LEPODO LEPOOD LEPOOD LODEOP LODEOP LODEPO LODEPO LODOEP LODOEP LODOPE LODOPE LODPEO LODPEO LODPOE LODPOE LOEDOP LOEDOP LOEDPO LOEDPO LOEODP LOEODP LOEOPD LOEOPD LOEPDO LOEPDO LOEPOD LOEPOD LOODEP LOODEP LOODPE LOODPE LOOEDP LOOEDP LOOEPD LOOEPD LOOPDE LOOPDE LOOPED LOOPED LOPDEO LOPDEO LOPDOE LOPDOE LOPEDO LOPEDO LOPEOD LOPEOD LOPODE LOPODE LOPOED LOPOED LPDEOO LPDEOO LPDOEO LPDOEO LPDOOE LPDOOE LPEDOO LPEDOO LPEODO LPEODO LPEOOD LPEOOD LPODEO LPODEO LPODOE LPODOE LPOEDO LPOEDO LPOEOD LPOEOD LPOODE LPOODE LPOOED LPOOED ODELOP ODELOP ODELPO ODELPO ODEOLP ODEOLP ODEOPL ODEOPL ODEPLO ODEPLO ODEPOL ODEPOL ODLEOP ODLEOP ODLEPO ODLEPO ODLOEP ODLOEP ODLOPE ODLOPE ODLPEO ODLPEO ODLPOE ODLPOE ODOELP ODOELP ODOEPL ODOEPL ODOLEP ODOLEP ODOLPE ODOLPE ODOPEL ODOPEL ODOPLE ODOPLE ODPELO ODPELO ODPEOL ODPEOL ODPLEO ODPLEO ODPLOE ODPLOE ODPOEL ODPOEL ODPOLE ODPOLE OEDLOP OEDLOP OEDLPO OEDLPO OEDOLP OEDOLP OEDOPL OEDOPL OEDPLO OEDPLO OEDPOL OEDPOL OELDOP OELDOP OELDPO OELDPO OELODP OELODP OELOPD OELOPD OELPDO OELPDO OELPOD OELPOD OEODLP OEODLP OEODPL OEODPL OEOLDP OEOLDP OEOLPD OEOLPD OEOPDL OEOPDL OEOPLD OEOPLD OEPDLO OEPDLO OEPDOL OEPDOL OEPLDO OEPLDO OEPLOD OEPLOD OEPODL OEPODL OEPOLD OEPOLD OLDEOP OLDEOP OLDEPO OLDEPO OLDOEP OLDOEP OLDOPE OLDOPE OLDPEO OLDPEO OLDPOE OLDPOE OLEDOP OLEDOP OLEDPO OLEDPO OLEODP OLEODP OLEOPD OLEOPD OLEPDO OLEPDO OLEPOD OLEPOD OLODEP OLODEP OLODPE OLODPE OLOEDP OLOEDP OLOEPD OLOEPD OLOPDE OLOPDE OLOPED OLOPED OLPDEO OLPDEO OLPDOE OLPDOE OLPEDO OLPEDO OLPEOD OLPEOD OLPODE OLPODE OLPOED OLPOED OODELP OODELP OODEPL OODEPL OODLEP OODLEP OODLPE OODLPE OODPEL OODPEL OODPLE OODPLE OOEDLP OOEDLP OOEDPL OOEDPL OOELDP OOELDP OOELPD OOELPD OOEPDL OOEPDL OOEPLD OOEPLD OOLDEP OOLDEP OOLDPE OOLDPE OOLEDP OOLEDP OOLEPD OOLEPD OOLPDE OOLPDE OOLPED OOLPED OOPDEL OOPDEL OOPDLE OOPDLE OOPEDL OOPEDL OOPELD OOPELD OOPLDE OOPLDE OOPLED OOPLED OPDELO OPDELO OPDEOL OPDEOL OPDLEO OPDLEO OPDLOE OPDLOE OPDOEL OPDOEL OPDOLE OPDOLE OPEDLO OPEDLO OPEDOL OPEDOL OPELDO OPELDO OPELOD OPELOD OPEODL OPEODL OPEOLD OPEOLD OPLDEO OPLDEO OPLDOE OPLDOE OPLEDO OPLEDO OPLEOD OPLEOD OPLODE OPLODE OPLOED OPLOED OPODEL OPODEL OPODLE OPODLE OPOEDL OPOEDL OPOELD OPOELD OPOLDE OPOLDE OPOLED OPOLED PDELOO PDELOO PDEOLO PDEOLO PDEOOL PDEOOL PDLEOO PDLEOO PDLOEO PDLOEO PDLOOE PDLOOE PDOELO PDOELO PDOEOL PDOEOL PDOLEO PDOLEO PDOLOE PDOLOE PDOOEL PDOOEL PDOOLE PDOOLE PEDLOO PEDLOO PEDOLO PEDOLO PEDOOL PEDOOL PELDOO PELDOO PELODO PELODO PELOOD PELOOD PEODLO PEODLO PEODOL PEODOL PEOLDO PEOLDO PEOLOD PEOLOD PEOODL PEOODL PEOOLD PEOOLD PLDEOO PLDEOO PLDOEO PLDOEO PLDOOE PLDOOE PLEDOO PLEDOO PLEODO PLEODO PLEOOD PLEOOD PLODEO PLODEO PLODOE PLODOE PLOEDO PLOEDO PLOEOD PLOEOD PLOODE PLOODE PLOOED PLOOED PODELO PODELO PODEOL PODEOL PODLEO PODLEO PODLOE PODLOE PODOEL PODOEL PODOLE PODOLE POEDLO POEDLO POEDOL POEDOL POELDO POELDO POELOD POELOD POEODL POEODL POEOLD POEOLD POLDEO POLDEO POLDOE POLDOE POLEDO POLEDO POLEOD POLEOD POLODE POLODE POLOED POLOED POODEL POODEL POODLE POODLE POOEDL POOEDL POOELD POOELD POOLDE POOLDE POOLED POOLED")
	assert(permutations("TRANCE") == "ACENRT ACENTR ACERNT ACERTN ACETNR ACETRN ACNERT ACNETR ACNRET ACNRTE ACNTER ACNTRE ACRENT ACRETN ACRNET ACRNTE ACRTEN ACRTNE ACTENR ACTERN ACTNER ACTNRE ACTREN ACTRNE AECNRT AECNTR AECRNT AECRTN AECTNR AECTRN AENCRT AENCTR AENRCT AENRTC AENTCR AENTRC AERCNT AERCTN AERNCT AERNTC AERTCN AERTNC AETCNR AETCRN AETNCR AETNRC AETRCN AETRNC ANCERT ANCETR ANCRET ANCRTE ANCTER ANCTRE ANECRT ANECTR ANERCT ANERTC ANETCR ANETRC ANRCET ANRCTE ANRECT ANRETC ANRTCE ANRTEC ANTCER ANTCRE ANTECR ANTERC ANTRCE ANTREC ARCENT ARCETN ARCNET ARCNTE ARCTEN ARCTNE ARECNT ARECTN ARENCT ARENTC ARETCN ARETNC ARNCET ARNCTE ARNECT ARNETC ARNTCE ARNTEC ARTCEN ARTCNE ARTECN ARTENC ARTNCE ARTNEC ATCENR ATCERN ATCNER ATCNRE ATCREN ATCRNE ATECNR ATECRN ATENCR ATENRC ATERCN ATERNC ATNCER ATNCRE ATNECR ATNERC ATNRCE ATNREC ATRCEN ATRCNE ATRECN ATRENC ATRNCE ATRNEC CAENRT CAENTR CAERNT CAERTN CAETNR CAETRN CANERT CANETR CANRET CANRTE CANTER CANTRE CARENT CARETN CARNET CARNTE CARTEN CARTNE CATENR CATERN CATNER CATNRE CATREN CATRNE CEANRT CEANTR CEARNT CEARTN CEATNR CEATRN CENART CENATR CENRAT CENRTA CENTAR CENTRA CERANT CERATN CERNAT CERNTA CERTAN CERTNA CETANR CETARN CETNAR CETNRA CETRAN CETRNA CNAERT CNAETR CNARET CNARTE CNATER CNATRE CNEART CNEATR CNERAT CNERTA CNETAR CNETRA CNRAET CNRATE CNREAT CNRETA CNRTAE CNRTEA CNTAER CNTARE CNTEAR CNTERA CNTRAE CNTREA CRAENT CRAETN CRANET CRANTE CRATEN CRATNE CREANT CREATN CRENAT CRENTA CRETAN CRETNA CRNAET CRNATE CRNEAT CRNETA CRNTAE CRNTEA CRTAEN CRTANE CRTEAN CRTENA CRTNAE CRTNEA CTAENR CTAERN CTANER CTANRE CTAREN CTARNE CTEANR CTEARN CTENAR CTENRA CTERAN CTERNA CTNAER CTNARE CTNEAR CTNERA CTNRAE CTNREA CTRAEN CTRANE CTREAN CTRENA CTRNAE CTRNEA EACNRT EACNTR EACRNT EACRTN EACTNR EACTRN EANCRT EANCTR EANRCT EANRTC EANTCR EANTRC EARCNT EARCTN EARNCT EARNTC EARTCN EARTNC EATCNR EATCRN EATNCR EATNRC EATRCN EATRNC ECANRT ECANTR ECARNT ECARTN ECATNR ECATRN ECNART ECNATR ECNRAT ECNRTA ECNTAR ECNTRA ECRANT ECRATN ECRNAT ECRNTA ECRTAN ECRTNA ECTANR ECTARN ECTNAR ECTNRA ECTRAN ECTRNA ENACRT ENACTR ENARCT ENARTC ENATCR ENATRC ENCART ENCATR ENCRAT ENCRTA ENCTAR ENCTRA ENRACT ENRATC ENRCAT ENRCTA ENRTAC ENRTCA ENTACR ENTARC ENTCAR ENTCRA ENTRAC ENTRCA ERACNT ERACTN ERANCT ERANTC ERATCN ERATNC ERCANT ERCATN ERCNAT ERCNTA ERCTAN ERCTNA ERNACT ERNATC ERNCAT ERNCTA ERNTAC ERNTCA ERTACN ERTANC ERTCAN ERTCNA ERTNAC ERTNCA ETACNR ETACRN ETANCR ETANRC ETARCN ETARNC ETCANR ETCARN ETCNAR ETCNRA ETCRAN ETCRNA ETNACR ETNARC ETNCAR ETNCRA ETNRAC ETNRCA ETRACN ETRANC ETRCAN ETRCNA ETRNAC ETRNCA NACERT NACETR NACRET NACRTE NACTER NACTRE NAECRT NAECTR NAERCT NAERTC NAETCR NAETRC NARCET NARCTE NARECT NARETC NARTCE NARTEC NATCER NATCRE NATECR NATERC NATRCE NATREC NCAERT NCAETR NCARET NCARTE NCATER NCATRE NCEART NCEATR NCERAT NCERTA NCETAR NCETRA NCRAET NCRATE NCREAT NCRETA NCRTAE NCRTEA NCTAER NCTARE NCTEAR NCTERA NCTRAE NCTREA NEACRT NEACTR NEARCT NEARTC NEATCR NEATRC NECART NECATR NECRAT NECRTA NECTAR NECTRA NERACT NERATC NERCAT NERCTA NERTAC NERTCA NETACR NETARC NETCAR NETCRA NETRAC NETRCA NRACET NRACTE NRAECT NRAETC NRATCE NRATEC NRCAET NRCATE NRCEAT NRCETA NRCTAE NRCTEA NREACT NREATC NRECAT NRECTA NRETAC NRETCA NRTACE NRTAEC NRTCAE NRTCEA NRTEAC NRTECA NTACER NTACRE NTAECR NTAERC NTARCE NTAREC NTCAER NTCARE NTCEAR NTCERA NTCRAE NTCREA NTEACR NTEARC NTECAR NTECRA NTERAC NTERCA NTRACE NTRAEC NTRCAE NTRCEA NTREAC NTRECA RACENT RACETN RACNET RACNTE RACTEN RACTNE RAECNT RAECTN RAENCT RAENTC RAETCN RAETNC RANCET RANCTE RANECT RANETC RANTCE RANTEC RATCEN RATCNE RATECN RATENC RATNCE RATNEC RCAENT RCAETN RCANET RCANTE RCATEN RCATNE RCEANT RCEATN RCENAT RCENTA RCETAN RCETNA RCNAET RCNATE RCNEAT RCNETA RCNTAE RCNTEA RCTAEN RCTANE RCTEAN RCTENA RCTNAE RCTNEA REACNT REACTN REANCT REANTC REATCN REATNC RECANT RECATN RECNAT RECNTA RECTAN RECTNA RENACT RENATC RENCAT RENCTA RENTAC RENTCA RETACN RETANC RETCAN RETCNA RETNAC RETNCA RNACET RNACTE RNAECT RNAETC RNATCE RNATEC RNCAET RNCATE RNCEAT RNCETA RNCTAE RNCTEA RNEACT RNEATC RNECAT RNECTA RNETAC RNETCA RNTACE RNTAEC RNTCAE RNTCEA RNTEAC RNTECA RTACEN RTACNE RTAECN RTAENC RTANCE RTANEC RTCAEN RTCANE RTCEAN RTCENA RTCNAE RTCNEA RTEACN RTEANC RTECAN RTECNA RTENAC RTENCA RTNACE RTNAEC RTNCAE RTNCEA RTNEAC RTNECA TACENR TACERN TACNER TACNRE TACREN TACRNE TAECNR TAECRN TAENCR TAENRC TAERCN TAERNC TANCER TANCRE TANECR TANERC TANRCE TANREC TARCEN TARCNE TARECN TARENC TARNCE TARNEC TCAENR TCAERN TCANER TCANRE TCAREN TCARNE TCEANR TCEARN TCENAR TCENRA TCERAN TCERNA TCNAER TCNARE TCNEAR TCNERA TCNRAE TCNREA TCRAEN TCRANE TCREAN TCRENA TCRNAE TCRNEA TEACNR TEACRN TEANCR TEANRC TEARCN TEARNC TECANR TECARN TECNAR TECNRA TECRAN TECRNA TENACR TENARC TENCAR TENCRA TENRAC TENRCA TERACN TERANC TERCAN TERCNA TERNAC TERNCA TNACER TNACRE TNAECR TNAERC TNARCE TNAREC TNCAER TNCARE TNCEAR TNCERA TNCRAE TNCREA TNEACR TNEARC TNECAR TNECRA TNERAC TNERCA TNRACE TNRAEC TNRCAE TNRCEA TNREAC TNRECA TRACEN TRACNE TRAECN TRAENC TRANCE TRANEC TRCAEN TRCANE TRCEAN TRCENA TRCNAE TRCNEA TREACN TREANC TRECAN TRECNA TRENAC TRENCA TRNACE TRNAEC TRNCAE TRNCEA TRNEAC TRNECA")
	assert(permutations("ASCENT") == "ACENST ACENTS ACESNT ACESTN ACETNS ACETSN ACNEST ACNETS ACNSET ACNSTE ACNTES ACNTSE ACSENT ACSETN ACSNET ACSNTE ACSTEN ACSTNE ACTENS ACTESN ACTNES ACTNSE ACTSEN ACTSNE AECNST AECNTS AECSNT AECSTN AECTNS AECTSN AENCST AENCTS AENSCT AENSTC AENTCS AENTSC AESCNT AESCTN AESNCT AESNTC AESTCN AESTNC AETCNS AETCSN AETNCS AETNSC AETSCN AETSNC ANCEST ANCETS ANCSET ANCSTE ANCTES ANCTSE ANECST ANECTS ANESCT ANESTC ANETCS ANETSC ANSCET ANSCTE ANSECT ANSETC ANSTCE ANSTEC ANTCES ANTCSE ANTECS ANTESC ANTSCE ANTSEC ASCENT ASCETN ASCNET ASCNTE ASCTEN ASCTNE ASECNT ASECTN ASENCT ASENTC ASETCN ASETNC ASNCET ASNCTE ASNECT ASNETC ASNTCE ASNTEC ASTCEN ASTCNE ASTECN ASTENC ASTNCE ASTNEC ATCENS ATCESN ATCNES ATCNSE ATCSEN ATCSNE ATECNS ATECSN ATENCS ATENSC ATESCN ATESNC ATNCES ATNCSE ATNECS ATNESC ATNSCE ATNSEC ATSCEN ATSCNE ATSECN ATSENC ATSNCE ATSNEC CAENST CAENTS CAESNT CAESTN CAETNS CAETSN CANEST CANETS CANSET CANSTE CANTES CANTSE CASENT CASETN CASNET CASNTE CASTEN CASTNE CATENS CATESN CATNES CATNSE CATSEN CATSNE CEANST CEANTS CEASNT CEASTN CEATNS CEATSN CENAST CENATS CENSAT CENSTA CENTAS CENTSA CESANT CESATN CESNAT CESNTA CESTAN CESTNA CETANS CETASN CETNAS CETNSA CETSAN CETSNA CNAEST CNAETS CNASET CNASTE CNATES CNATSE CNEAST CNEATS CNESAT CNESTA CNETAS CNETSA CNSAET CNSATE CNSEAT CNSETA CNSTAE CNSTEA CNTAES CNTASE CNTEAS CNTESA CNTSAE CNTSEA CSAENT CSAETN CSANET CSANTE CSATEN CSATNE CSEANT CSEATN CSENAT CSENTA CSETAN CSETNA CSNAET CSNATE CSNEAT CSNETA CSNTAE CSNTEA CSTAEN CSTANE CSTEAN CSTENA CSTNAE CSTNEA CTAENS CTAESN CTANES CTANSE CTASEN CTASNE CTEANS CTEASN CTENAS CTENSA CTESAN CTESNA CTNAES CTNASE CTNEAS CTNESA CTNSAE CTNSEA CTSAEN CTSANE CTSEAN CTSENA CTSNAE CTSNEA EACNST EACNTS EACSNT EACSTN EACTNS EACTSN EANCST EANCTS EANSCT EANSTC EANTCS EANTSC EASCNT EASCTN EASNCT EASNTC EASTCN EASTNC EATCNS EATCSN EATNCS EATNSC EATSCN EATSNC ECANST ECANTS ECASNT ECASTN ECATNS ECATSN ECNAST ECNATS ECNSAT ECNSTA ECNTAS ECNTSA ECSANT ECSATN ECSNAT ECSNTA ECSTAN ECSTNA ECTANS ECTASN ECTNAS ECTNSA ECTSAN ECTSNA ENACST ENACTS ENASCT ENASTC ENATCS ENATSC ENCAST ENCATS ENCSAT ENCSTA ENCTAS ENCTSA ENSACT ENSATC ENSCAT ENSCTA ENSTAC ENSTCA ENTACS ENTASC ENTCAS ENTCSA ENTSAC ENTSCA ESACNT ESACTN ESANCT ESANTC ESATCN ESATNC ESCANT ESCATN ESCNAT ESCNTA ESCTAN ESCTNA ESNACT ESNATC ESNCAT ESNCTA ESNTAC ESNTCA ESTACN ESTANC ESTCAN ESTCNA ESTNAC ESTNCA ETACNS ETACSN ETANCS ETANSC ETASCN ETASNC ETCANS ETCASN ETCNAS ETCNSA ETCSAN ETCSNA ETNACS ETNASC ETNCAS ETNCSA ETNSAC ETNSCA ETSACN ETSANC ETSCAN ETSCNA ETSNAC ETSNCA NACEST NACETS NACSET NACSTE NACTES NACTSE NAECST NAECTS NAESCT NAESTC NAETCS NAETSC NASCET NASCTE NASECT NASETC NASTCE NASTEC NATCES NATCSE NATECS NATESC NATSCE NATSEC NCAEST NCAETS NCASET NCASTE NCATES NCATSE NCEAST NCEATS NCESAT NCESTA NCETAS NCETSA NCSAET NCSATE NCSEAT NCSETA NCSTAE NCSTEA NCTAES NCTASE NCTEAS NCTESA NCTSAE NCTSEA NEACST NEACTS NEASCT NEASTC NEATCS NEATSC NECAST NECATS NECSAT NECSTA NECTAS NECTSA NESACT NESATC NESCAT NESCTA NESTAC NESTCA NETACS NETASC NETCAS NETCSA NETSAC NETSCA NSACET NSACTE NSAECT NSAETC NSATCE NSATEC NSCAET NSCATE NSCEAT NSCETA NSCTAE NSCTEA NSEACT NSEATC NSECAT NSECTA NSETAC NSETCA NSTACE NSTAEC NSTCAE NSTCEA NSTEAC NSTECA NTACES NTACSE NTAECS NTAESC NTASCE NTASEC NTCAES NTCASE NTCEAS NTCESA NTCSAE NTCSEA NTEACS NTEASC NTECAS NTECSA NTESAC NTESCA NTSACE NTSAEC NTSCAE NTSCEA NTSEAC NTSECA SACENT SACETN SACNET SACNTE SACTEN SACTNE SAECNT SAECTN SAENCT SAENTC SAETCN SAETNC SANCET SANCTE SANECT SANETC SANTCE SANTEC SATCEN SATCNE SATECN SATENC SATNCE SATNEC SCAENT SCAETN SCANET SCANTE SCATEN SCATNE SCEANT SCEATN SCENAT SCENTA SCETAN SCETNA SCNAET SCNATE SCNEAT SCNETA SCNTAE SCNTEA SCTAEN SCTANE SCTEAN SCTENA SCTNAE SCTNEA SEACNT SEACTN SEANCT SEANTC SEATCN SEATNC SECANT SECATN SECNAT SECNTA SECTAN SECTNA SENACT SENATC SENCAT SENCTA SENTAC SENTCA SETACN SETANC SETCAN SETCNA SETNAC SETNCA SNACET SNACTE SNAECT SNAETC SNATCE SNATEC SNCAET SNCATE SNCEAT SNCETA SNCTAE SNCTEA SNEACT SNEATC SNECAT SNECTA SNETAC SNETCA SNTACE SNTAEC SNTCAE SNTCEA SNTEAC SNTECA STACEN STACNE STAECN STAENC STANCE STANEC STCAEN STCANE STCEAN STCENA STCNAE STCNEA STEACN STEANC STECAN STECNA STENAC STENCA STNACE STNAEC STNCAE STNCEA STNEAC STNECA TACENS TACESN TACNES TACNSE TACSEN TACSNE TAECNS TAECSN TAENCS TAENSC TAESCN TAESNC TANCES TANCSE TANECS TANESC TANSCE TANSEC TASCEN TASCNE TASECN TASENC TASNCE TASNEC TCAENS TCAESN TCANES TCANSE TCASEN TCASNE TCEANS TCEASN TCENAS TCENSA TCESAN TCESNA TCNAES TCNASE TCNEAS TCNESA TCNSAE TCNSEA TCSAEN TCSANE TCSEAN TCSENA TCSNAE TCSNEA TEACNS TEACSN TEANCS TEANSC TEASCN TEASNC TECANS TECASN TECNAS TECNSA TECSAN TECSNA TENACS TENASC TENCAS TENCSA TENSAC TENSCA TESACN TESANC TESCAN TESCNA TESNAC TESNCA TNACES TNACSE TNAECS TNAESC TNASCE TNASEC TNCAES TNCASE TNCEAS TNCESA TNCSAE TNCSEA TNEACS TNEASC TNECAS TNECSA TNESAC TNESCA TNSACE TNSAEC TNSCAE TNSCEA TNSEAC TNSECA TSACEN TSACNE TSAECN TSAENC TSANCE TSANEC TSCAEN TSCANE TSCEAN TSCENA TSCNAE TSCNEA TSEACN TSEANC TSECAN TSECNA TSENAC TSENCA TSNACE TSNAEC TSNCAE TSNCEA TSNEAC TSNECA")
}

func assert(x bool) {
	if !x {
		panic("assertion failed")
	}
}

func permutations(s string) string {
	var t []string
	recurse([]rune(s), 0, &t)
	sort.Strings(t)
	return strings.Join(t, " ")
}

func recurse(r []rune, n int, t *[]string) {
	*t = append(*t, string(r))
	for i := n; i < len(r); i++ {
		for j := i + 1; j < len(r); j++ {
			r[i], r[j] = r[j], r[i]
			recurse(r, i+1, t)
			r[i], r[j] = r[j], r[i]
		}
	}
}