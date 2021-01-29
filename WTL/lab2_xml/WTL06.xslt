<?xml version="1.0"?>

<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:template match="/">
  <html>
  <body>
    <h2>My Movie Collection</h2>
    <table border="1">
      <tr bgcolor="#9acd32">
        <th>Movie Id</th>
        <th>Movie Name</th>
		<th>Release Date</th>
		<th>Genre</th>
		<th>Actors</th>
		<th>Age</th>
      </tr>
      <xsl:for-each select="books/book">
        <tr>
          <td><xsl:value-of select="title"/></td>
          <td><xsl:value-of select="category"/></td>
		  <td><xsl:value-of select="author"/></td>
		  <td><xsl:value-of select="publisher"/></td>
          <td><xsl:value-of select="year"/></td>
		  <td><xsl:value-of select="isbn"/></td>
        </tr>
      </xsl:for-each>
    </table>
  </body>
  </html>
</xsl:template>

</xsl:stylesheet>
