<?xml version="1.0"?> 
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output encoding="UTF-16"/>

<!-- XSLT - Numbering - format= "&#x5b50;" (Zodiac 12) & = "&#x7532;" (Zodiac 10)  -->
<!-- & = "&#x7532;&#x5b50;" (Zodiac 60) -  letter-value="alphabetic" | "traditional" -->
<!-- Created : Khalil Jabrane -->
<!-- Date: 04/12/2000 -->

<xsl:template match="/">  
	<TABLE>  
		<xsl:for-each select="//humanoid">
			<TR><TD>  
				<TD>
					<!-- Zodiac 12 -->
					<xsl:number format="&#x5b50;" letter-value="traditional"/> *					
					<xsl:value-of select = "text()"/>
				</TD>
				<TD>|---|</TD>
				<TD>
					<!-- zodiac 10 -->
					<xsl:number format="&#x7532;" lang="fi" letter-value="traditional" /> *					
					<xsl:value-of select = "text()"/>
				</TD>
				<TD>|---|</TD>
				<TD>
					<!-- zodiac 60 -->
					<xsl:number format="&#x7532;&#x5b50;" letter-value="traditional" /> *					
					<xsl:value-of select = "text()"/>
				</TD>
			</TD></TR>
		</xsl:for-each>  
	</TABLE>
</xsl:template>  

</xsl:stylesheet>  

